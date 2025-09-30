#include <stdio.h>

// Function to find max in array
int findMax(int arr[], int n) {
    int max = arr[0];  // assume first element is max
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int numbers[] = {3, 17, 9, 21, 14};
    int size = 5;

    int maxValue = findMax(numbers, size);

    printf("Maximum value = %d\n", maxValue);
    return 0;
}
