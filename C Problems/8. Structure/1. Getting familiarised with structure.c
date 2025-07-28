#include<stdio.h>
#include<string.h>
    typedef struct student{
        char name[50];
        int id;
        char dep[10];
    }student;


int main()
{   int n, i;
    student s[50];
    printf("Input the number of students : ");
    scanf("%d", &n);
    getchar();
    for(i=0; i<n; i++)
    {
        printf("Name of student %d : ", i+1);
        fgets(s[i].name, 50, stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0';

        printf("ID of student %d : ", i+1);
        scanf("%d", &s[i].id);
        getchar();

        printf("Department of student %d : ", i+1);
        fgets(s[i].dep, 10, stdin);
        s[i].dep[strcspn(s[i].dep, "\n")] = '\0';
    }
    for(i=0; i<n; i++)
    {
      printf(" Student number : %d\n", i+1);
      printf("Name: %s\nID: %d\nDepartment: %s", s[i].name,s[i].id, s[i].dep );
    }

}

