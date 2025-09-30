/*
Write a program to check whether the entered year is leap year or not (a year is leap if it
is divisible by 4 and divisible by 100 or 400.)
*/

#include <stdio.h>

int main() {
    int year;
    {printf("Enter a year : ");}
    scanf("%d", &year);

    if ((year%4==0&&year%100!=0)||(year%400==0))
        {printf("Leap year\n");}
    else
        {printf("Not a leap year\n");}

    return 0;
}
