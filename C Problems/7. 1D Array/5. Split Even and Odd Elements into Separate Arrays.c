//Write a program to split even and odd elements of an array into two arrays

#include <stdio.h>

int main() 
{
    int arr[100], even[100], odd[100];
    int i, n;
    int evenCount = 0, oddCount = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);


        if(arr[i] % 2 == 0) 
       {
            even[evenCount] = arr[i];
            evenCount++;
       }
     else 
       {
            odd[oddCount] = arr[i];
            oddCount++;
       }
    }


    printf("\nEven elements: ");
    for(i = 0; i < evenCount; i++) {
        printf("%d ", even[i]);
    }

    printf("\nOdd elements: ");
    for(i = 0; i < oddCount; i++) {
        printf("%d ", odd[i]);
    }

    return 0;
}
