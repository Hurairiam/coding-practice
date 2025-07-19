/*
3. Write a C program that takes number of days as input, and then converts it into years and days,
and displays the results. Assume that, 1 year = 365 days.
Input : 735
Output : 2 years 5days
*/

#include <stdio.h>

int main() {
    int days, years;
    printf("Enter number of days : ");
    scanf("%d", &days);
    years=days/365;
    days=days%365;
    printf("%d years %d days\n", years, days);
    return 0;
}

