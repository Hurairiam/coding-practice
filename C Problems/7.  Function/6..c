#include <stdio.h>

// Function to calculate sum
int arraySum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int n = 5;

    int total = arraySum(arr, n);

    printf("Sum of array elements = %d\n", total);
    return 0;
}
