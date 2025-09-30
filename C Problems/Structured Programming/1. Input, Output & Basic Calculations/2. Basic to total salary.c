/*
Write a C program to calculate and display the total salary of an employee considering that
total salary is the sum of basic salary and house rent. The program must ask the user for the basic
salary and percentage of basic salary which determines the house rent.
Input : 25000 10
Output: 27500
*/

#include <stdio.h>

int main()
{
    float basic, per;
    printf("Enter basic salary and percentage for house rent : ");
    scanf("%f %f", &basic, &per);
    printf("Total Salary: %.0f\n", basic+(basic*per/100));
    return 0;
}
