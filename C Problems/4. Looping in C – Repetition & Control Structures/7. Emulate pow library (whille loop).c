//Write a program to emulate the pow library function where the parameters will be user input using a while loop.

#include <stdio.h>

int main() {
    int base, exponent, result = 1;
    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);

    int i = 1;
    while(i <= exponent) {
        result *= base;
        i++;
    }

    printf("%d^%d = %d\n", base, exponent, result);
    return 0;
}
