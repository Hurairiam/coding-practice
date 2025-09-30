#include <stdio.h>

typedef struct {
    int ID;
    char name[100];
    char subjects[3][50];
    int marks[3];
} Student;

int main() {
    int n = 5;
    Student s[5];
    float avg;

    printf("Enter Information for %d Students:\n", n);

    for (int i = 0; i < n; i++) {
        printf("\nStudent %d ID: ", i + 1);
        scanf("%d", &s[i].ID);
        getchar();  // consume newline

        printf("Student %d Name: ", i + 1);
        gets(s[i].name);

        for (int j = 0; j < 3; j++) {
            printf("Student %d Subject %d: ", i + 1, j + 1);
            gets(s[i].subjects[j]);

            printf("Student %d Subject %d Marks: ", i + 1, j + 1);
            scanf("%d", &s[i].marks[j]);
            getchar();  // consume newline
        }
    }

    printf("\n--- Student Results ---\n");

    for (int i = 0; i < n; i++) {
        int sum = 0;
        printf("\nStudent name: %s\n", s[i].name);
        printf("Student ID: %d\n", s[i].ID);

        for (int j = 0; j < 3; j++) {
            printf("Subject: %s\nMarks: %d\n", s[i].subjects[j], s[i].marks[j]);
            sum += s[i].marks[j];
        }

        avg = sum / 3.0f;
        printf("Average: %.2f\n", avg);
        printf("Result: %s\n", (avg >= 50) ? "Passed" : "Failed");
    }

    return 0;
}
