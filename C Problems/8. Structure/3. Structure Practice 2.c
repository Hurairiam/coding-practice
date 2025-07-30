/*Create a structure called “Student” that will hold information such as the student's ID, name, and three
subject marks. Develop a C program that allows for the input of data for five students, calculates their
average marks, and displays the information along with whether they passed or failed (pass if the
average is 50 or above)*/

#include<stdio.h>

typedef struct Name
{
   char firstName[50];
   char secondName[50];
}Name;

typedef struct Subs
{
   char subs1[50];
   char subs2[50];
   char subs3[50];
}Subs;
typedef struct Marks
{
   int marks1;
   int marks2;
   int marks3;
}Marks;

typedef struct Student
{
   int ID;
   Name n;
   Marks m;
   Subs sb;

}Student;

int main()
{
int i, n;
float avg;

Student s[50];


printf("Number of Students: ");
scanf("%d", &n);
printf("Enter Information: \n");

    for(int i=0; i<n; i++)
    {
        printf("Enter student's ID: ");
        scanf("%d", &s[i].ID);
        printf("Enter student's name: ");
        scanf("%s %s", s[i].n.firstName, s[i].n.secondName);
        printf("Enter first subject and marks: ");
        scanf("%s %d", s[i].sb.subs1, &s[i].m.marks1);
        printf("Enter second subject and marks: ");
        scanf("%s %d", s[i].sb.subs2, &s[i].m.marks2);
        printf("Enter third subject and marks: ");
        scanf("%s %d", s[i].sb.subs3, &s[i].m.marks3);
    }

    for(int i=0; i<n; i++)
    {
        avg=(s[i].m.marks1+s[i].m.marks2+s[i].m.marks3)/3.0;

        printf("Students name: %s %s\n", s[i].n.firstName, s[i].n.secondName);

        printf("Students ID: %d\n", s[i].ID);

        printf("Subject: %s\n Marks: %d\n", s[i].sb.subs1, s[i].m.marks1);
        printf("Subject: %s\n Marks: %d\n", s[i].sb.subs2, s[i].m.marks2);
        printf("Subject: %s\n Marks: %d\n", s[i].sb.subs3, s[i].m.marks3);

        printf("Average: %.2f\n", avg);
        (avg>=50)? printf("Passed") : printf("Failed");
  }

    return 0;

}
























