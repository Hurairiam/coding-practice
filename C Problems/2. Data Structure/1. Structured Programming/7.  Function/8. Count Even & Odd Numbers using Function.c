#include <stdio.h>

// Function to count even & odd
void countEvenOdd(int arr[], int n, int *even, int *odd) {
    *even = 0;
    *odd = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            (*even)++;
        else
            (*odd)++;
    }
}

int main() {
    int arr[] = {2, 5, 8, 11, 14, 17};
    int n = 6;
    int evenCount, oddCount;

    countEvenOdd(arr, n, &evenCount, &oddCount);

    printf("Even count = %d\n", evenCount);
    printf("Odd count = %d\n", oddCount);

    return 0;
}
