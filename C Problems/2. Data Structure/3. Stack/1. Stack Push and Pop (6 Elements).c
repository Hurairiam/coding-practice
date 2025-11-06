#include <stdio.h>
#define MAX 6   // Maximum stack size

int stack[MAX];
int top = -1;

// Push function
void push()
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        int value;
        printf("Enter value to push into the stack: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

// Pop function that returns the popped element
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! No element to pop.\n");
        return -1;
    }
    else
    {
        int value = stack[top];
        top--;
        return value;
    }
}

int main()
{
    int i;
    printf("Push 6 elements into the stack:\n");
    for (i = 0; i < MAX; i++)
    {
        push();
    }

    printf("\nPopping elements from the stack:\n");
    while (top != -1)
    {
        printf("%d\n", pop());
    }

    return 0;
}
