Write a program to find the sum of a series of positive odd numbers using recursion.

#include <stdio.h>

int sumOdd(int n) {
    if (n == 0) 
        return 0;  
    return (2 * n - 1) + sumOdd(n - 1);  
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Sum of first %d odd numbers = %d\n", n, sumOdd(n));
    return 0;
}