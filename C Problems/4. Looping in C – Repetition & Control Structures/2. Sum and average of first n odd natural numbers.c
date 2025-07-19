//Write a program to calculate and display the sum and average of first n odd natural numbers

#include <stdio.h>

int main()
{
    int n, sum=0, count=0;
    printf("Enter how many terms you want: ");
    scanf("%d", &n);

    for(int i=1; count<n; i++) {
        if(i%2!=0) {
            sum+=i;
            count++;
        }
    }

    printf("Sum=%d\nAverage=%.2f\n", sum, (float)sum/n);
    return 0;
}
