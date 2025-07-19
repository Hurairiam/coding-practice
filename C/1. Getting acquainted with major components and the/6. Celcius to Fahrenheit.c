/*
6. Convert Celsius temperature to Fahrenheit.
T (°F) = T (°C) × 9/5 + 32
Input: 20
Output: Celsius = 68
*/

#include <stdio.h>

int main()
{
    float c;
    scanf("%f", &c);
    printf("Celsius = %.0f\n", c*9/5+32);
    return 0;
}
