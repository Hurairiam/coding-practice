#include <stdio.h>

int main() {
    int row=3, col=3;
    int arr[row][col];
    int trans[col][row];


    printf("Enter the elements of the array:\n");
    for (int i=0; i<row; i++)
        {
        for (int j=0; j<col; j++)
        {
            printf("arr1[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
        }


    for (int i=0; i<row; i++)
        {
        for (int j=0; j<col; j++)
        {
            trans[j][i]=arr[i][j];
        }
        }

    printf("\nThe array is:\n");
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }


    printf("\nTranspose of the array:\n");
    for (int i=0; i<col; i++)
        {
        for (int j=0; j<row; j++)
        {
            printf("%d ",trans[i][j]);
        }
        printf("\n");
    }



    return 0;
}