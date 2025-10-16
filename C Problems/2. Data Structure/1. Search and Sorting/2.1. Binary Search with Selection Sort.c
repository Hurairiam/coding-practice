
#include<stdio.h>

int main()
{

int arr[100], n, i, j, search, pos, t, low, high, mid;

printf("Enter the number of elements in the array : ");
scanf("%d", &n);
for(i=0; i<n; i++)
{
    printf("\nEnter the element number %d : ", i+1);
    scanf("%d",&arr[i]);
}
//selection sort

for(i=0; i<n-1; i++)
{
    pos=i;

    for(j=i+1; j<n; j++)
    {
        if(arr[j]<arr[pos])
            pos=j;
    }
    if(pos!=i)
    {
        t=arr[i];
        arr[i]=arr[pos];
        arr[pos]=t;
    }
}

//binary sort

printf("\nEnter the element to search : \n");
scanf("%d", &search);

low=0;
high=n-1;
mid=(low+high)/2;
while(low<=high)
{
    if(arr[mid]==search)
    {
        printf("\nThe Element %d is found at the index %d\n", search, mid+1);
        break;
    }
    else if(arr[mid]<search)
        low=mid+1;
    else
        high=mid-1;

        mid=(low+high)/2;
}
if(low>high)
    printf("Not found! %d is not present in the array", search);

    /*printf("\nThe sorted array elements are:\n\n");
    for(i=0;i<n;i++)
        printf("%d  ", arr[i]);*/

return 0;
}
