#include <stdio.h>
int main()
{
    int i, n, pos, arr[10];

    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("\n Print the element number %d :", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the position from which the number has to be deleted :\n");
    scanf("%d", &pos);

    for(i=pos; i<n-1; i++)
    arr[i]=arr[i+1];
    n--;

    printf("\n The array after deletion is : ");
    for(i=0; i<n; i++)
    {
        printf("\n arr[%d]= %d", i, arr[i]);
    }

    return 0;
}
