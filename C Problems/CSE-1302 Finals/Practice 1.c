#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top=NULL;

void push(int val)
{   struct node *new=malloc(sizeof(struct node));

    if(new==NULL)
    {
        printf("Stack Overflow!\n"); //Heap memory full
        return;
    }
    new->data=val;
    new->next=top;
    top=new;
    printf("%d pushed\n", val);
}

void pop()
{
    if(top==NULL)
    {
        printf("Stack Underflow!\n");
        return;
    }
    struct node *temp=top;
    int val=temp->data;
    top=top->next;
    free(temp);
    printf("%d popped\n", val);
}

void display()
{
        if(top==NULL)
    {
        printf("Stack is empty!\n");
        return;
    }

    struct node *temp=top;
    printf("Stack elements are : \n");

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
    push(5);
    pop();
    push(99);
    push(6);
    display();
}
