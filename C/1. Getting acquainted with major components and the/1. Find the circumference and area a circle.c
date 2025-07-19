/*
1. Write a C program to enter the radius of a circle and find its circumference and area. Note that
Circumference = 2 x π x radius, Area = π x (radius)2, and assume π=3.1416
Input : 2
Output 12.560
*/

#include <stdio.h>

int main()
{
    float rad;
    printf("Enter the radius of the circle: ");
    scanf("%f", &rad);
    printf("Circumference: %.2f\n", 2*3.1416*rad);
    printf("Area: %.2f\n", 3.1416*rad*rad);
    return 0;
}
