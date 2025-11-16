#include <stdio.h>
#include <stdlib.h>

int *stack;
int front=-1;
int rear=-1;
int MAX;

void enqueue()
{
    if(rear==MAX-1)
    {printf("Queue Overflow!\n");}
    else
    {
        int value;
        printf("Enter value to enqueue: ");
        scanf("%d", &value);
        if(front==-1)
            front=0;
        rear++;
        stack[rear]=value;
        printf("%d enqueued into queue.\n", value);
    }
}

int dequeue()
{
    if(front==-1||front>rear)
    {
        printf("Queue Underflow!\n");
        return -1;
    }
    else
    {
        int value=stack[front];
        front++;
        if(front>rear)
            front=rear=-1;
        return value;
    }
}

void display()
{
    if(front==-1||front>rear)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements:\n");
    for(int i=front; i<=rear; i++)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    printf("Enter the queue size: ");
    scanf("%d", &MAX);

    stack=(int*)malloc(MAX * sizeof(int));
    if(stack==NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int choice;

while(1)
{
system("cls");

printf("\n");
printf("\t=====================\n");
printf("\t|    QUEUE MENU     |\n");
printf("\t=====================\n\n");
printf("\t1. Enqueue\n");
printf("\t2. Dequeue\n");
printf("\t3. Display\n");
printf("\t4. Exit\n\n");
printf("\tEnter your choice: ");
scanf("%d", &choice);

system("cls");

switch(choice)
    {
    case 1:
    {
        enqueue();
        break;
    }

    case 2:
    {
        int val=dequeue();
        if(val!=-1)
            {printf("Dequeued: %d\n", val);}
        break;
    }

    case 3:
    {
        display();
        break;
    }

    case 4:
    {
        printf("Exiting program.\n");
        free(stack);
        return 0;
    }

    default:
        {printf("Invalid choice! Try again.\n");}
    }

    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}
}
