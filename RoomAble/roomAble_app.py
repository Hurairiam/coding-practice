import pandas as pd
import re
from datetime import datetime
import os
import io
from flask import Flask, request, render_template_string, send_from_directory
from pywebio.platform.flask import webio_view
from pywebio import STATIC_PATH
from pywebio.input import *
from pywebio.output import *
from pywebio.session import *

app = Flask(__name__)

# HTML Template for the main page
HTML_TEMPLATE = """
<!DOCTYPE html>
<html>
<head>
    <title>RoomAble - Web Version</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    {{ pywebio_output }}
</head>
<body>
</body>
</html>
"""

class RoomAvailabilityApp:
    def __init__(self):
        self.schedule_data = []
        self.all_rooms = set()
        self.default_file = "class_schedule.xlsx"
        
    def parse_day(self, day_str):
        """Handle combined days like 'Sun &Tue' or 'Thu & SAT'"""
        day_str = str(day_str).strip()
        if "&" in day_str:
            return [d.strip()[:3] for d in day_str.split("&")]
        return [day_str[:3]]
    
    def extract_rooms(self, text):
        """Extract all room numbers from a cell's text"""
        room_pattern = re.compile(r'\b(PA|PB|PC|PD)\s*\d+[A-Z]?\b', re.IGNORECASE)
        return [match.group().upper() for match in room_pattern.finditer(text)]
    
    def parse_time(self, time_str):
        """Handle all time formats in the schedule"""
        time_str = re.sub(r'\s*:\s*', ':', time_str)
        time_str = re.sub(r'\s+', ' ', time_str).strip()
        
        if "-" in time_str:
            time_str = time_str.split("-")[0].strip()
        
        try:
            return datetime.strptime(time_str, "%I:%M %p").time()
        except ValueError:
            return datetime.strptime(time_str, "%H:%M").time()
    
    def process_file(self, file_content):
        try:
            with io.BytesIO(file_content) as file:
                df = pd.read_excel(file, header=None)
            
            self.schedule_data = []
            self.all_rooms = set()
            
            header_row = None
            for i, row in df.iterrows():
                if "Day /Time" in str(row[0]):
                    header_row = i
                    break
            
            if header_row is None:
                toast("Error: Could not find 'Day /Time' header row", color='error')
                return False
            
            current_days = None
            for i in range(header_row + 1, len(df)):
                row = df.iloc[i]
                
                if pd.notna(row[0]):
                    current_days = self.parse_day(row[0])
                
                if not current_days:
                    continue
                
                for j in range(1, 8):
                    if pd.isna(row[j]):
                        continue
                    
                    time_slot = df.iloc[header_row, j]
                    cell_content = str(row[j])
                    
                    rooms = self.extract_rooms(cell_content)
                    for room in rooms:
                        self.all_rooms.add(room)
                        for day in current_days:
                            self.schedule_data.append({
                                'day': day,
                                'time_slot': time_slot,
                                'room': room
                            })
            
            toast(f"Loaded {len(self.all_rooms)} rooms from schedule", color='success')
            return True
            
        except Exception as e:
            toast(f"Failed to process file: {str(e)}", color='error')
            return False
    
    def check_availability(self, check_time, check_day):
        try:
            check_time = self.parse_time(check_time)
            check_day = check_day[:3]
            
            occupied_rooms = set()
            for entry in self.schedule_data:
                if entry['day'] != check_day:
                    continue
                
                try:
                    time_slot = entry['time_slot']
                    if not isinstance(time_slot, str) or "-" not in time_slot:
                        continue
                    
                    start_str, end_str = [t.strip() for t in time_slot.split("-", 1)]
                    start_time = self.parse_time(start_str)
                    end_time = self.parse_time(end_str)
                    
                    if start_time <= check_time <= end_time:
                        occupied_rooms.add(entry['room'])
                except Exception as e:
                    print(f"Skipping invalid time slot: {time_slot} - {str(e)}")
            
            return occupied_rooms
            
        except ValueError as e:
            toast(f"Invalid time format: {str(e)}", color='error')
            return None

def roomable_app():
    app = RoomAvailabilityApp()
    
    # Password protection (optional)
    # if not os.environ.get('PYTHONANYWHERE_SITE'):
    #     password = input("Enter access password:", type=PASSWORD)
    #     if password != "YOUR_SECRET":
    #         return
    
    put_markdown("""
    # 🏫 RoomAble - Available Rooms Finder
    *Find available classrooms at your institution*
    """)
    
    # File upload section
    file = file_upload(
        "Upload schedule Excel file:", 
        accept=".xlsx,.xls",
        help_text="Upload your class schedule file (Excel format)"
    )
    
    if file:
        with use_scope('status', clear=True):
            put_loading(shape='grow', color='primary')
            put_text("Processing file...")
            
        success = app.process_file(file['content'])
        
        with use_scope('status', clear=True):
            if not success:
                return
    
    # Time selection
    col1, col2 = columns(2)
    
    with col1:
        time = input(
            "Enter time (HH:MM AM/PM):",
            type=TEXT,
            value=datetime.now().strftime("%I:%M %p").lstrip("0"),
            help_text="Example: 10:30 AM or 14:00"
        )
    
    with col2:
        day = select(
            "Select day:",
            options=['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun'],
            value=datetime.now().strftime("%a")
        )
    
    # Check availability button
    if actions(buttons=['Find Available Rooms'], position='center'):
        with use_scope('results', clear=True):
            put_loading(shape='border', color='dark')
            put_text("Checking availability...")
            
            occupied_rooms = app.check_availability(time, day)
            if occupied_rooms is None:
                return
            
            buildings = {
                'PA': {'available': [], 'occupied': []},
                'PB': {'available': [], 'occupied': []},
                'PC': {'available': [], 'occupied': []},
                'PD': {'available': [], 'occupied': []}
            }
            
            for room in app.all_rooms:
                building = room[:2]
                status = 'occupied' if room in occupied_rooms else 'available'
                buildings[building][status].append(room)
            
            # Display results in tabs
            with put_tabs():
                for building, rooms in buildings.items():
                    with put_tab(f"{building} Building"):
                        total_available = len(rooms['available'])
                        put_markdown(f"### {total_available} rooms available")
                        
                        if total_available > 0:
                            put_table([
                                ['Room', 'Floor', 'Status']] +
                                [
                                    [room, room[2], '✅ Available'] 
                                    for room in sorted(
                                        rooms['available'],
                                        key=lambda x: int(re.search(r'\d+', x).group())
                                    )
                                ],
                                style='grid'
                            )
                        else:
                            put_warning(f"No rooms available in {building} building")
                        
                        if rooms['occupied']:
                            put_collapse("Show occupied rooms", [
                                put_table([
                                    ['Room', 'Floor', 'Status']] +
                                    [
                                        [room, room[2], '❌ Occupied'] 
                                        for room in sorted(rooms['occupied'])
                                    ]
                                )
                            ])

@app.route('/')
def index():
    return render_template_string(HTML_TEMPLATE)

@app.route('/roomable', methods=['GET', 'POST'])
def webio_view_wrapper():
    return webio_view(roomable_app)()

@app.route('/static/<path:filename>')
def send_static(filename):
    return send_from_directory(STATIC_PATH, filename)

if __name__ == '__main__':
    from pywebio.platform.flask import start_server
    start_server(
        roomable_app,
        port=8080,
        debug=True,
        host='0.0.0.0',
        cdn=False,
        allowed_origins=None
    )