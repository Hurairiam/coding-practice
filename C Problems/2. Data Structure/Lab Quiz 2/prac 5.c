#include<stdio.h>
#define MAX 100

int queue[MAX];
int size;
int front=-1;
int rear=-1;

void enqueue()
{
    int val;
    printf("Enter value to be enqueued : \n");
    scanf("%d", &val);

    if(rear==size-1)
    {
        printf("Queue Overflow!\n");
    }
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        queue[rear]=val;
    }
    else
    {
        rear++;
        queue[rear]=val;
    }
}

int dequeue()
{
    int val;
    if(front==-1||front>rear)
    {
        printf("Queue Underflow\n");
    }
    else if(front==rear)

     {
        val=queue[front];
        printf("%d dequeued\n",val);
        front=rear=-1;
        return val;

    }
    else
    {
        val=queue[front];
        printf("%d dequeued\n",val);
        front++;
        return val;

    }
}

void display()
{
    if(front==-1||front>rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(int i=front; i<=rear; i++)
            printf("%d ", queue[i]);
            printf("\n");
    }
}

int main
