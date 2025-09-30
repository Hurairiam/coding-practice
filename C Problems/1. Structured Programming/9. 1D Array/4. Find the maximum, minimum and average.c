//Write a program to find the maximum, minimum and average from a list of floating-point numbers.

#include <stdio.h>

int main() {
    int n;
    float numbers[100], sum = 0, max, min, avg;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%f", &numbers[i]);
        sum += numbers[i];

        if(i == 0) {
            max = min = numbers[i];
        } else {
            if(numbers[i] > max)
                max = numbers[i];
            if(numbers[i] < min)
                min = numbers[i];
        }
    }

    avg = sum / n;

    // Output
    printf("\nMaximum value: %.2f\n", max);
    printf("Minimum value: %.2f\n", min);
    printf("Average value: %.2f\n", avg);

    return 0;
}

