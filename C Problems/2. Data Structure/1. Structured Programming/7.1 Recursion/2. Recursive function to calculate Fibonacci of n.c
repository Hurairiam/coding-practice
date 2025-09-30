//Write a recursive function to generate Fibonacci series.

#include <stdio.h>

// Recursive function to calculate Fibonacci of n
int fibonacci(int n) {
    if (n == 0) return 0;  // base case
    if (n == 1) return 1;  // base case
    return fibonacci(n - 1) + fibonacci(n - 2);  // recursion
}

int main() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}
