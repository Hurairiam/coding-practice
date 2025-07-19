/*
Write a program that will give a choice menu. Using switch for coding
Take two inputs and one operator and do the calculation.
Press ‘+’: Add two number
Press ‘-’: Subtract two number
Press ‘*’: Multiply two number
Press ‘/’: Division two number
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

    switch(op)
    {
        case '+':
            printf("%.2f\n", a+b);
            break;
        case '-':
            printf("%.2f\n", a-b);
            break;
        case '*':
            printf("%.2f\n", a*b);
            break;
        case '/':
            if(b==0)
                printf("Division by zero not possible\n");
            else
                printf("%.2f\n", a/b);
            break;
        default:
            printf("Invalid operator\n");
    }

    return 0;
}
