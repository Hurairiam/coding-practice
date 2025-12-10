#include <stdio.h>
#define MAX 100

int stack[MAX];
int top=-1;
int size;

void push()
{
    if(top==size-1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        int val;
        printf("Enter value to push into the stack: ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
        printf("%d pushed to stack.\n", val);
    }
}

// Pop function
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! No element to pop.\n");
        return -1;
    }
    else
    {
        int val=stack[top];
        top--;
        return val;
    }
}

// Display function
void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements (top to bottom): ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, times, i;

    printf("Enter the stack size (<= %d): ", MAX);
    scanf("%d", &size);

    while (1)
    {
        printf("\nChoose an option:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("How many values do you want to push? ");
            scanf("%d", &times);

            for (i = 0; i < times; i++)
            {
                push();
            }
        }
        else if (choice == 2)
        {
            int popped = pop();
            if (popped != -1)
            {
                printf("Popped value: %d\n", popped);
            }
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 0)
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid option! Try again.\n");
        }
    }

    return 0;
}
