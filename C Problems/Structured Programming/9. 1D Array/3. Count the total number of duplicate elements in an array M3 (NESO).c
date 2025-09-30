//Write a program in C to count the total number of duplicate elements in an array

#include <stdio.h>

int main() {
    int seen[10] = {0}; // Array to track digits (0–9)
    int N, rem;

    // Part 1: Input
    printf("Enter the number: ");
    scanf("%d", &N);

    // Part 2: Check for repeated digits
    while (N > 0) {
        rem = N % 10; // Get last digit

        if (seen[rem] == 1) { // Digit already seen
            break;
        }

        seen[rem] = 1; // Mark digit as seen
        N = N / 10;    // Remove last digit
    }

    // Part 3: Output
    if (N > 0)
        printf("Yes\n"); // Repeated digit found
    else
        printf("No\n");  // All digits unique

    return 0;
}
