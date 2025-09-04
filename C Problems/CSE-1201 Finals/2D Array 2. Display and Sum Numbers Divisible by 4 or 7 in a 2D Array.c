/*
Write a program to display the numbers divisible by 4 or 7 from a 2D array of integers and find the sum of those numbers as well
*/

#include <stdio.h>

int main() {
    int rows, cols;
    int arr[50][50];
    int sum = 0;

    // Input number of rows and columns
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input elements of the 2D array
    printf("Enter elements of the array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Numbers divisible by 4 or 7:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] % 4 == 0 || arr[i][j] % 7 == 0) {
                printf("%d ", arr[i][j]);
                sum += arr[i][j]; // Add to sum
            }
        }
    }
    printf("\nSum of these numbers: %d\n", sum);

    return 0;
}
