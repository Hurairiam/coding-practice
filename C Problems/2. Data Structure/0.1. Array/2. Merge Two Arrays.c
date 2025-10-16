#include <stdio.h>
int main()
{
    int arr1[10], arr2[10], arr3[20];
    int i, n1, n2, index = 0;

    printf("\n Enter the number of elements in the first array : ");
    scanf("%d", &n1);

    printf("\n\n Enter the elements of the first array");
    for(i =0; i<n1; i++)
    {
        printf("\n arr1[%d] = ", i);
        scanf("%d", &arr1[i]);
    }

    printf("\n Enter the number of elements in the second array : ");
    scanf("%d", &n2);

    printf("\n\n Enter the elements of the second array");
    for(i=0; i<n2; i++)
    {
        printf("\n arr2[%d] = ", i);
        scanf("%d", &arr2[i]);
    }

    for(i=0; i<n1; i++)
    {
        arr3[index]=arr1[i];
        index++;
    }

    for(i=0; i<n2; i++)
    {
        arr3[index]=arr2[i];
        index++;
    }

    printf("\n The merged array is : ");
    for(i=0; i<index; i++)
    {
        printf("\n arr3[%d] = %d", i, arr3[i]);
    }

    return 0;
}