//Write a program using while Loop to calculate the factorial value of any integer entered through the keyboard.

#include <stdio.h>

int main()
{
    int n, fact=1, i=1;
    printf("Enter a number: ");
    scanf("%d", &n);

    while(i<=n)
    {
        fact*=i;
        i++;
    }

    printf("Factorial=%d\n", fact);
    return 0;
}

