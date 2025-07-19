/*
Find out average of four numbers
Input: 5 8 4 6
Output: Average = 5.75
*/

#include <stdio.h>

int main()
{
    float a, b, c, d;
    printf("Enter four numbers : ");
    scanf("%f %f %f %f", &a, &b, &c, &d);
    printf("Average = %.2f\n", (a+b+c+d)/4);
    return 0;
}
