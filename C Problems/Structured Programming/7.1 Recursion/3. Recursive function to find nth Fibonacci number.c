#include <stdio.h>

// Recursive function to find nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) return 0;  // base case
    if (n == 1) return 1;  // base case
    return fibonacci(n - 1) + fibonacci(n - 2); // recursive call
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("The %dth Fibonacci number is: %d\n", n, fibonacci(n));

    return 0;
}
