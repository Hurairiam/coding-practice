//Fibonacci

#include <stdio.h>

int main()
{
    int n, num1=0, num2=1, num3;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("\nFibonacci series:\n");
    for(int i=1; i<=n; i++) {
        printf("%d ", num1);
        num3=num1+num2;
        num1=num2;
        num2=num3;
    }

    printf("\n\nLast term: %d\n", num1);
    return 0;
}
