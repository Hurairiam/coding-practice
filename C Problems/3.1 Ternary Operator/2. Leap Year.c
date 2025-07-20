/*
Leap Year Checker
Write a program that reads a year and uses a ternary operator to print whether the year is a leap year or not.

Leap year rules:

Year divisible by 400 → leap year

Year divisible by 100 but not 400 → not leap year

Year divisible by 4 but not 100 → leap year

Otherwise → not leap year
*/

#include<stdio.h>
int main()
{
    int year;
    printf("Enter year : ");
    scanf("%d", &year);
    (year%4==0&&year%100!=0||year%400==0)? printf("Leap Year") : printf("Not Leap Year");
    return 0;

}
