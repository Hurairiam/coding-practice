#include<stdio.h>
#define SIZE 10

int top=-1;
int stack[SIZE];

void push(int val)
{
    if(top==SIZE-1)
    {
        printf("Stack Overflow!");
    }
    else
    {
        top++;
        stack[top]=val;
        printf("%d pushed\n", val);
    }
}

int pop()
{
    if(top==-1)
    {
        printf("Stack Underflow!");
        return -1;
    }
    else
    {
        int val=stack[top];
        top--;
        printf("%d popped\n", val);
        return val;
    }
}

void display()
{
    if(top==-1)
    {
        printf("Stack is empty!");
    }
    else
    {   printf("Stack Elements : ");
        for(int i=top; i>=0; i--)
        {
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
        }
    }
}


int main()
{
    push(10);
    push(11);
    push(17);
    push(18);
    display();
    pop();
    display();

    return 0;
}
