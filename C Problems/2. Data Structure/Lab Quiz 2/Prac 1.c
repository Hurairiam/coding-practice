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
        printf("Stack Underflow!\n");
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
        printf("Stack is empty!\n");
    }
    else
    {   printf("Stack Elements : \n");
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
    push(1);
    push(2);
    push(3);
    push(4);
    pop();
    push(5);
    display();

    return 0;
}
