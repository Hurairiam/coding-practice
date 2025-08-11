/*
Write a function in C to find the prime numbers within a range of numbers.
Pass the range as a parameter.
Input: Lower Range: 1 Upper Range: 50
Output : 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
*/

#include <stdio.h>

void findPrimes(int lower, int upper) {
    printf("Prime numbers between %d and %d are:\n", lower, upper);

    for (int num = lower; num <= upper; num++) {
        if (num <= 1) continue;

        int count = 0;
        for (int i = 1; i <= num; i++) {
            if (num % i == 0) {
                count++;
            }
        }
        if (count == 2) {
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

    findPrimes(lowerRange, upperRange);

    return 0;
}
