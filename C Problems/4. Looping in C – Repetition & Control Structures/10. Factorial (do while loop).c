//Write a program using do while Loop to calculate the factorial value of any integer entered through the keyboard.

#include <stdio.h>

int main()
{
    int n, fact=1, i=1;
    printf("Enter a number: ");
    scanf("%d", &n);

    if(n==0) fact=1;
    else {
        do {
            fact*=i;
            i++;
        } while(i<=n);
    }

    printf("Factorial=%d\n", fact);
    return 0;
}


