#include <stdio.h>

int main() {
    int rows, cols;
    int mat1[50][50], mat2[50][50], diffMat[50][50];

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

    // Subtract matrices: diffMat = mat1 - mat2
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            diffMat[i][j] = mat1[i][j] - mat2[i][j];

    printf("Difference of the two matrices (mat1 - mat2):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", diffMat[i][j]);
        printf("\n");
    }

    return 0;
}
