//Write a C program that takes input for a 2x2 matrix from the user and computes its determinant. The program should then display the determinant value.

#include <stdio.h>

int main() {
    int matrix[2][2];
    int det;

    printf("Enter elements of 2x2 matrix:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &matrix[i][j]);

    det = matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];

    printf("Determinant of the matrix is: %d\n", det);

    return 0;
}
