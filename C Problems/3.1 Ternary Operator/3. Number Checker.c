/*
Write a program that takes an integer and uses nested ternary operators to classify it as:

"Positive Even"

"Positive Odd"

"Negative Even"

"Negative Odd"

"Zero"
*/

#include<stdio.h>
int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    //(n<0)? printf("Negative ") : printf("Positive ") ;
    //(n%2==0)? printf("Even") : printf("Odd") ;
    (n>0)?((n%2==0)? printf("Positive Even") : printf("Positive Odd")):
        ((n<0)?
        ((n%2==0) ? printf("Negative Even") : printf("Negative Odd")) : printf("Zero"));

    return 0;

}
