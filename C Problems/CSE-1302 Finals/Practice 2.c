#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int val)
{
    struct node *new=malloc(sizeof(struct node));
    if(new==NULL)
    {
        printf("Queue Overflow!\n"); //Heap memory full
        return;
    }
    new->data=val;
    new->next=NULL;

    if(front==NULL)
    {
        front=rear=new;
        printf("%d enqueued!\n", val);
    }
    else
    {
        rear->next=new;
        rear=new;
        printf("%d enqueued!\n", val);
    }
}
void dequeue()
{
    if(front==NULL)
    {
        printf("Queue Underflow!\n");
        return;
    }
        struct node *temp=front;
        int val=temp->data;
        front=front->next;
        if(front==NULL)
        {
            rear=NULL;
        }
        free(temp);
        printf("%d dequeued!\n", val);

    }




void display()
{
    if(front==NULL)
    {
        printf("Queue is empty!\n");
    }

    struct node *temp=front;
    printf("Queue elements are : \n");

    while(temp!=NULL)
    {

    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
    }
}



int main()
{
    enqueue(55);
    enqueue(22);
    enqueue(52);
    dequeue();
    dequeue();
    display();
}


