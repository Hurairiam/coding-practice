#include <stdio.h>

int main() {
    int rows, cols;
    int mat1[50][50], mat2[50][50], sumMat[50][50];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat1[i][j]);

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat2[i][j]);

    // Add matrices
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sumMat[i][j] = mat1[i][j] + mat2[i][j];

    printf("Sum of the two matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", sumMat[i][j]);
        printf("\n");
    }

    return 0;
}
