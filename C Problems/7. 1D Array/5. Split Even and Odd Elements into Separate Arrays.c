
#include<stdio.h>

int main()
{
    int og[100], even[100], odd[100];
    int i, n;
    int evenCount=0, oddCount=0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", &og[i]);


        if(og[i]%2==0)
       {
            even[evenCount]=og[i];
            evenCount++;
       }
     else
       {
            odd[oddCount]=og[i];
            oddCount++;
       }
    }


    printf("\nEven elements: ");
    for(i=0; i<evenCount; i++)
    {printf("%d ", even[i]);}

    printf("\nOdd elements: ");
    for(i=0; i<oddCount; i++)
    {printf("%d ", odd[i]);}

    return 0;
}
