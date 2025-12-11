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

struct node* delEnd(struct node *head)
{
    if(head==NULL)
    {
        printf("Nothing to delete!");
    }
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    struct node *temp=head;
    while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
        return head;


};


int main()

{
    struct node *n1=malloc(sizeof(struct node));
    struct node *n2=malloc(sizeof(struct node));
    struct node *n3=malloc(sizeof(struct node));
    struct node *n4=malloc(sizeof(struct node));
    struct node *head;

    n1->data=13;
    n2->data=17;
    n3->data=43;
    n4->data=45;

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=NULL;
    head=n1;

    head=insertBeg(head, 26);
    head=delEnd(head);


    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->", temp->data);
        temp=temp->next;
    }
        printf("NULL");

}
