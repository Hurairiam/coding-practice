/*
Take two inputs from user and find out sum, subtract multiplication and
division.
Input: 8 2
Output: Sum=10, Subtract=6, Multiplication= 16, Division = 4
Special Condition: If you divide by 0, it will show “not possible to divide by 0”
*/

#include <stdio.h>

int main()
{
    float a, b;
    printf("Enter two numbers : ");
    scanf("%f %f", &a, &b);
    printf("Sum = %.2f\n", a+b);
    printf("Subtract = %.2f\n", a-b);
    printf("Multiplication = %.2f\n", a*b);
    if(b == 0)
        printf("not possible to divide by 0\n");
    else
        printf("Division = %.2f\n", a/b);
    return 0;
}
