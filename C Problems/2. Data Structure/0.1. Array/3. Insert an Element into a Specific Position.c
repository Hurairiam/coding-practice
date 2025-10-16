#include <stdio.h>

int main()
{
    int arr[20], n, num, pos, i;

    // Input array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Input array elements
    printf("\nEnter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    // Input number to insert and its position
    printf("\nEnter the number to be inserted: ");
    scanf("%d", &num);

    printf("Enter the position (0 to %d) where it should be inserted: ", n);
    scanf("%d", &pos);

    // Validate position
    if(pos < 0 || pos > n)
    {
        printf("Invalid position! Position must be between 0 and %d.\n", n);
        return 1;
    }

    // Shift elements to the right
    for(i = n - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }

    // Insert new element
    arr[pos] = num;
    n++; // Increase size

    // Print updated array
    printf("\nThe array after insertion:\n");
    for(i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}
