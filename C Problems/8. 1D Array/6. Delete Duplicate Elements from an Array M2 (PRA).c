//Write a program to delete duplicate elements from an array

#include <stdio.h>

int main() {
    int a[100];
    int n, pos;
    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    printf("Enter which index has to be deleted: ");
    scanf("%d", &pos);
    
    for(int i=pos; i<n-1; i++){
        a[i] = a[i+1];
    }
    n--;
    
    printf("Array after deletion:\n");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }

    
}