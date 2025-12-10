#include<stdio.h>
#define SIZE 10

int queue[SIZE];
int front=-1;
int rear=-1;

void enqueue(int val)
{
    if(rear==SIZE-1)
    {
        printf("Queue Overflow!\n");
    }

    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        queue[rear]=val;
        printf("%d enqueued\n", val);
    }

    else
    {
        rear++;
        queue[rear]=val;
        printf("%d enqueued\n", val);
    }
}

void dequeue()
{

    if(front==-1||front>rear)
    {
        printf("Queue Underflow!\n");
    }

    else if(front==rear)
    {
        printf("%d dequeued\n", queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("%d dequeued\n", queue[front]);
        front++;
    }
}

void display()
{
    if(front==-1||front>rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {   printf("Queue list : \n");
        for(int i=front; i<=rear; i++)
        {
            printf("%d ", queue[i]);
        printf("\n");
        }

    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    enqueue(5);
    display();


    return;
}
