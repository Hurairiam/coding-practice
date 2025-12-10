#include<stdio.h>
#define SIZE 10

int queue[SIZE];
int front=-1;
int rear=-1;

void enqueue()
{
    if(rear==SIZE-1)
    {
     printf("Queue Overflow!");
    }
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        int val;
        printf("Enter value to queue : ");
        scanf("%d", val);
        queue[rear]=val
    }

}


