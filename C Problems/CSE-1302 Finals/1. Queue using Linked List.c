#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node
{
    int data;
    struct node *next;
};

/* Front and Rear pointers */
struct node *front = NULL;
struct node *rear = NULL;

/* ENQUEUE operation */
void enqueue()
{
    int val;
    printf("Enter value to enqueue: ");
    scanf("%d", &val);

    struct node *new = malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("Queue Overflow (Heap full)\n");
        return;
    }

    new->data = val;
    new->next = NULL;

    if (front == NULL) // empty queue
    {
        front = rear = new;
    }
    else
    {
        rear->next = new;
        rear = new;
    }

    printf("%d enqueued into queue\n", val);
}

/* DEQUEUE operation */
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow! Queue is empty\n");
        return;
    }

    struct node *temp = front;
    int val = temp->data;

    front = front->next;

    // If queue becomes empty
    if (front == NULL)
        rear = NULL;

    free(temp);
    printf("Dequeued value: %d\n", val);
}

/* DISPLAY operation */
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    printf("Queue elements (front to rear): ");

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
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            enqueue();
        else if (choice == 2)
            dequeue();
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
