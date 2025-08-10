/*
Write a program in C that reads a 5 × 5 array of integers from the user. After reading the values:

Display the sum of each row.

Display the sum of each column.

Program Input/Output Specification:

First, the program will prompt for each row separately.

After all rows are entered, the program will print the row totals and then the column totals.
*/

#include <stdio.h>

int main() {
    int arr[5][5];
    int rowSum[5] = {0};
    int colSum[5] = {0};

    // Input
    for (int i = 0; i < 5; i++) {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < 5; j++) {
            scanf("%d", &arr[i][j]);
            rowSum[i] += arr[i][j]; // Add to row sum
            colSum[j] += arr[i][j]; // Add to column sum
        }
    }

    // Output row sums
    printf("Row total: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", rowSum[i]);
    }
    printf("\n");

    // Output column sums
    printf("Column total: ");
    for (int j = 0; j < 5; j++) {
        printf("%d ", colSum[j]);
    }
    printf("\n");

    return 0;
}
