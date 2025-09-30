/*
Write a program to input two integer numbers and display the sum of even numbers
between these two input numbers.
*/

#include <stdio.h>

int main()
{
    int a, b, sum=0, start, end;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    if(a < b)
    {start=a;
     end=b;}
    else
    {start=b;
     end=a;}

    for(int i=start+1; i<end; i++)
        {if(i%2==0){sum+=i;}}

    printf("Sum of even numbers between %d and %d = %d\n", a, b, sum);
    return 0;
}

