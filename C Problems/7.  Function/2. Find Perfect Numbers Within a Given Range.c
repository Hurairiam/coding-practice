/*
Write a function in c program to find the perfect numbers within a given number of ranges.
Pass the range as a parameter.
Input: Lower Range: 1 Upper Range: 50
Output: 6 28
*/

#include <stdio.h>

void findPerfectNumbers(int lower, int upper) {
    printf("Perfect numbers between %d and %d are:\n", lower, upper);
    for (int num = lower; num <= upper; num++) {
        int sum = 0;
        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) {
                sum += i;
            }
        }
        if (sum == num && num != 0) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

int main() {
    int lowerRange, upperRange;

    printf("Enter lower range: ");
    scanf("%d", &lowerRange);

    printf("Enter upper range: ");
    scanf("%d", &upperRange);

    findPerfectNumbers(lowerRange, upperRange);

    return 0;
}
