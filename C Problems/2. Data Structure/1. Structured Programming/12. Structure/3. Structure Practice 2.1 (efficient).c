#include <stdio.h>
#include <string.h>

typedef struct {
    char firstName[50];
    char secondName[50];
} Name;

typedef struct {
    char subs1[50];
    char subs2[50];
    char subs3[50];
} Subs;

typedef struct {
    int marks1;
    int marks2;
    int marks3;
} Marks;

typedef struct {
    int ID;
    Name n;
    Marks m;
    Subs sb;
} Student;

void trimNewline(char *str) {
    str[strcspn(str, "\n")] = 0;  // Remove trailing newline if present
}

int main() {
    int n = 5;  // fixed number of students
    Student s[5];
    float avg;

    printf("Enter Information for %d Students:\n", n);

    for (int i = 0; i < n; i++) {
        char buffer[100];

        printf("\nStudent %d ID: ", i+1);
        fgets(buffer, sizeof(buffer), stdin);
        s[i].ID = atoi(buffer);

        printf("Student %d First Name: ", i+1);
        fgets(s[i].n.firstName, sizeof(s[i].n.firstName), stdin);
        trimNewline(s[i].n.firstName);

        printf("Student %d Second Name: ", i+1);
        fgets(s[i].n.secondName, sizeof(s[i].n.secondName), stdin);
        trimNewline(s[i].n.secondName);

        printf("Student %d First Subject: ", i+1);
        fgets(s[i].sb.subs1, sizeof(s[i].sb.subs1), stdin);
        trimNewline(s[i].sb.subs1);

        printf("Student %d First Subject Marks: ", i+1);
        fgets(buffer, sizeof(buffer), stdin);
        s[i].m.marks1 = atoi(buffer);

        printf("Student %d Second Subject: ", i+1);
        fgets(s[i].sb.subs2, sizeof(s[i].sb.subs2), stdin);
        trimNewline(s[i].sb.subs2);

        printf("Student %d Second Subject Marks: ", i+1);
        fgets(buffer, sizeof(buffer), stdin);
        s[i].m.marks2 = atoi(buffer);

        printf("Student %d Third Subject: ", i+1);
        fgets(s[i].sb.subs3, sizeof(s[i].sb.subs3), stdin);
        trimNewline(s[i].sb.subs3);

        printf("Student %d Third Subject Marks: ", i+1);
        fgets(buffer, sizeof(buffer), stdin);
        s[i].m.marks3 = atoi(buffer);
    }

    printf("\n--- Student Results ---\n");

    for (int i = 0; i < n; i++) {
        avg = (s[i].m.marks1 + s[i].m.marks2 + s[i].m.marks3) / 3.0f;

        printf("\nStudent name: %s %s\n", s[i].n.firstName, s[i].n.secondName);
        printf("Student ID: %d\n", s[i].ID);
        printf("Subject: %s\nMarks: %d\n", s[i].sb.subs1, s[i].m.marks1);
        printf("Subject: %s\nMarks: %d\n", s[i].sb.subs2, s[i].m.marks2);
        printf("Subject: %s\nMarks: %d\n", s[i].sb.subs3, s[i].m.marks3);
        printf("Average: %.2f\n", avg);
        printf("Result: %s\n", (avg >= 50) ? "Passed" : "Failed");
    }

    return 0;
}
