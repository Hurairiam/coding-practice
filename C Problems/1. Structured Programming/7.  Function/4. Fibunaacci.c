#include <stdio.h>

// Function to print first n Fibonacci numbers
void printFibonacci(int n) {
    int num1 = 0, num2 = 1, num3;

    printf("\nFibonacci series:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", num1);
        num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printFibonacci(n);

    return 0;
}
