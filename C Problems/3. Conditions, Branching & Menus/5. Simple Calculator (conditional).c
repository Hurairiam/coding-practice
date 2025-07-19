/*
Write a program that will give a choice menu. Using if for coding
Take two inputs and one operator and do the calculation.
Press ‘+’: Add two numbers
Press ‘-’: Subtract two numbers
Press ‘*’: Multiply two numbers
Press ‘/’: Division two numbers
Input: 8 / 10
Output: 0.80
*/

#include <stdio.h>

int main()
{
    float a, b;
    char op;
    printf("Enter first number, a operator and 2nd number respectively :  ");
    scanf("%f %c %f", &a, &op, &b);

     if(op=='+')
        {printf("%.2f\n", a+b);}
else if(op=='-')
        {printf("%.2f\n", a-b);}
else if(op=='*')
        {printf("%.2f\n", a*b);}
else if(op == '/') {

    if(b == 0)
        {printf("Division by zero not possible\n");}
    else{printf("%.2f\n", a/b);}
    }

    return 0;
}
