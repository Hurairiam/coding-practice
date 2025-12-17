#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node
{
    int data;
    struct node *next;
};

/* Top of stack */
struct node *top = NULL;

/* PUSH operation */
void push()
{
    int val;
    struct node *new = malloc(sizeof(struct node));

    if (new == NULL)
    {
        printf("Stack Overflow (Heap memory full)\n");
        return;
    }

    printf("Enter value to push: ");
    scanf("%d", &val);

    new->data = val;
    new->next = top;
    top = new;

    printf("%d pushed into stack\n", val);
}

/* POP operation */
void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow! Stack is empty\n");
        return;
    }

    struct node *temp = top;
    int val = temp->data;

    top = top->next;
    free(temp);

    printf("Popped value: %d\n", val);
}

/* DISPLAY operation */
void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    struct node *temp = top;
    printf("Stack elements (top to bottom): ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* MAIN function */
int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            push();
        else if (choice == 2)
            pop();
        else if (choice == 3)
            display();
        else if (choice == 0)
        {
            printf("Exiting...\n");
            break;
        }
        else
            printf("Invalid choice!\n");
    }

    return 0;
}
