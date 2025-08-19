#include <stdio.h>

// Function to reverse array
void reverseArray(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    printf("Original array: ");
    printArray(arr, n);

    reverseArray(arr, n);

    printf("Reversed array: ");
    printArray(arr, n);

    return 0;
}
