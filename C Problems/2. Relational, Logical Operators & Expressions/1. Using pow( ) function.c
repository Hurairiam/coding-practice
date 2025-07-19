/*
Write a program in C that computes the value for z, where z = x^3 + 3*(x^2)*(y^4)+y^2.
The value of x and y should be taken from the user. Use pow() function to solve this problem
*/

#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, z;
    printf("Enter the values of x and y : ");
    scanf("%lf %lf", &x, &y);
    z = pow(x, 3)+3*pow(x, 2)*pow(y, 4)+pow(y, 2);
    printf("z = %.2lf\n", z);
    return 0;
}
