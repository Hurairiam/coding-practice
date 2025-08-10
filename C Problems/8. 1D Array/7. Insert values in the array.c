//Write a program in C to insert values in the array

#include <stdio.h>

int main()
{
    int n, i, value, pos;
    int arr[100];

    printf("Input the size of array : ");
    scanf("%d", &n);

    printf("Input %d elements in the array in ascending order: \n", n);
    for(i=0; i<n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("Input the value to be inserted : ");
    scanf("%d", &value);

    printf("Input the Position, where the value to be inserted :");
    scanf("%d", &pos);

    printf("The current list of the array :\n");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
        printf("\n");
    for(i=n; i>pos; i--)
    {arr[i]=arr[i-1];}

    arr[pos]=value;
    n++;

    printf("After Insert the element the new list is :\n");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
        printf("\n");

    return 0;
}
