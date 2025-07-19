//Write a program to emulate the pow library function where the parameters will be user input using a while loop.

#include <stdio.h>

int main() {
    int base, expo, result=1;

    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &expo);

    for(int i=1; i<=expo; i++)
        {result*=base;}

    printf("%d^%d = %d\n", base, expo, result);
    return 0;
}
