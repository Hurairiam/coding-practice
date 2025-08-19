#include <stdio.h>

// Function to search element
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // return index
        }
    }
    return -1; // not found
}

int main() {
    int arr[] = {10, 25, 30, 45, 50};
    int n = 5, key = 30;

    int index = linearSearch(arr, n, key);

    if (index != -1)
        printf("Element %d found at index %d\n", key, index);
    else
        printf("Element %d not found\n", key);

    return 0;
}
