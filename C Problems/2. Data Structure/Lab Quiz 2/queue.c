#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;
int size;

// Enqueue function
void enqueue()
{
    int val;

    if (rear == size - 1)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        printf("Enter value to enqueue: ");
        scanf("%d", &val);

        if (front == -1 && rear == -1) // first element
            front = rear = 0;
        else
            rear++;

        queue[rear] = val;
        printf("%d enqueued to queue.\n", val);
    }
}

// Dequeue function
int dequeue()
{
    int val;

    if (front == -1 || front > rear) // empty queue
    {
        printf("Queue Underflow!\n");
        return -1;
    }
    else
    {
        val = queue[front];
        if (front == rear) // only one element
            front = rear = -1;
        else
            front++;

        return val;
    }
}

// Display function
void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements (front to rear): ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    int choice, times, i;

    printf("Enter the queue size (<= %d): ", MAX);
    scanf("%d", &size);

    while (1)
    {
        printf("\nChoose an option:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("How many values do you want to enqueue? ");
            scanf("%d", &times);

            for (i = 0; i < times; i++)
            {
                enqueue();
            }
        }
        else if (choice == 2)
        {
            int val = dequeue();
            if (val != -1)
                printf("Dequeued value: %d\n", val);
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
