#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node* insertBeg(struct node *head, int val)
{
    struct node *new=malloc(sizeof(struct node));
    new->data=val;
    new->next=head;
    head=new;
    return head;
};

struct node* insertEnd(struct node *head, int val)
{
    struct node *new=malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;

    if(head==NULL)
    {
        head=new;
        return head;
    }
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
    return head;
};

struct node* insertPos(struct node *head, int val, int pos)
{
    struct node *new=malloc(sizeof(struct node));
    new->data=val;
    if(head==NULL)
    {
        new->next=head;
        head=new;
        return head;
    }
    struct node *temp=head;
    for(int i=0; i<pos-1; i++)
    {
        if(temp==NULL)
        {
            printf("Position out of range!");
        }
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
    return head;
};


int main()
{
    struct node *n1=malloc(sizeof(struct node));
    struct node *n2=malloc(sizeof(struct node));
    struct node *n3=malloc(sizeof(struct node));
    struct node *n4=malloc(sizeof(struct node));
    struct node *head;

    n1->data=12;
    n2->data=23;
    n3->data=44;
    n4->data=51;

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=NULL;

    head=n1;


    head=insertBeg(head, 890);
    head=insertEnd(head, 123);
    head=insertPos(head, 69, 2);









    struct node *temp=head;
    while(temp!=0)
    {
        printf("%d-> ", temp->data);
        temp=temp->next;
    }
    printf("NULL");


    return 0;

}
