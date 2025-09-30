#include <stdio.h>

int main() 
{
    int array[100], n, c, d, position, t;

    printf("Enter number of elements\n");
    scanf("%d", &n);

    printf("Enter %d integers\n", n);
    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);

    // Selection sort
    for (c = 0; c < n - 1; c++) 
    {
        position = c;

        // Find the minimum element in the unsorted part
        for (d = c + 1; d < n; d++) 
        {
            if (array[position] > array[d])
                position = d;
        }

        // Swap if a smaller element is found
        if (position != c) 
        {
            t = array[c];
            array[c] = array[position];
            array[position] = t;
        }
    }

    printf("Sorted list in ascending order:\n");
    for (c = 0; c < n; c++)
        printf("%d ", array[c]);

    printf("\n");
    return 0;
}
