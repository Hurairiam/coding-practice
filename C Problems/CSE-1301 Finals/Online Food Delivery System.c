#include <stdio.h>
#include <stdlib.h>
#define MAX_ORDER 20
#define MAX_CUSTO 20

int orderStack[MAX_ORDER];
int top=-1;
int custoQueue[MAX_CUSTO];
int front=-1, rear=-1;

void pushOrder();
int popOrder();
void peekOrder();
void displayOrder();
void enqueueCusto();
int dequeueCusto();
void peekCusto();
void displayCusto();


int main()
{
    int choice, sub, val, order, custo;

    while(1)
    {
        system("cls");


        printf("========================================\n");
        printf("        ONLINE FOOD DELIVERY SYSTEM     \n");
        printf("========================================\n\n");

        printf("1. Kitchen (Manage Orders)\n");
        printf("2. Customers (Manage Delivery Queue)\n");
        printf("3. Deliver ORDER\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        system("cls");

        switch(choice)
        {
            case 1:
            {
                printf("--- Kitchen Menu ---\n");
                printf("1. Add ORDER (Push)\n");
                printf("2. Remove order from kitchen (Pop)\n");
                printf("3. Peek Next ORDER\n");
                printf("4. Display Orders\n");
                printf("Enter choice: ");
                scanf("%d", &sub);

                if(sub==1)
                    pushOrder();
                else if(sub==2)
                {
                    val=popOrder();
                    if(val!=-1)
                    printf("Order %d removed from kitchen.\n", val);
                }
                else if(sub==3)
                    peekOrder();
                else if(sub==4)
                    displayOrder();
                else printf("Invalid choice!\n");
                break;
            }

            case 2:
            {
                printf("--- Customer Menu ---\n");
                printf("1. Add Customer (Enqueue)\n");
                printf("2. Remove Customer (Dequeue)\n");
                printf("3. Peek Next Customer\n");
                printf("4. Display Customers\n");
                printf("Enter choice: ");
                scanf("%d", &sub);

                if(sub==1)
                    enqueueCusto();
                else if(sub==2)
                {
                    val=dequeueCusto();
                    if(val!=-1)
                    printf("Customer %d removed from queue.\n", val);
                }
                else if(sub==3)
                    peekCusto();
                else if(sub==4)
                    displayCusto();
                else
                    printf("Invalid choice!\n");
                break;
            }

            case 3:
                if(top==-1)
                    printf("No orders to deliver!\n");
                else if(front==-1||front>rear)
                    printf("No customers waiting!\n");
                else
                {
                    order=popOrder();
                    custo=dequeueCusto();
                    printf("Delivered ORDER %d to Customer %d.\n", order, custo);
                }
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }

    return 0;
}


void pushOrder()
{
    if(top==MAX_ORDER-1)
        printf("Cannot add more orders! Kitchen full.\n");
    else
    {
        int ORDER;
        top++;
        printf("Enter ORDER ID: ");
        scanf("%d", &ORDER);
        orderStack[top]=ORDER;
        printf("ORDER %d added.\n", ORDER);
    }
}

int popOrder()
{
    int ORDER;
    if(top==-1)
    {
        printf("No prepared orders!\n");
        return -1;
    }
    ORDER=orderStack[top];
    top--;
    return ORDER;
}

void peekOrder()
{
    if(top==-1)
        printf("No orders in kitchen.\n");
    else
        printf("Next ORDER to deliver: %d\n", orderStack[top]);
}

void displayOrder()
{
    if(top==-1)
    {
        printf("No orders in kitchen.\n");
        return;
    }
    printf("Orders in kitchen (Top to Bottom):\n");
    for(int i=top; i>=0; i--)
    printf("%d\n", orderStack[i]);
}


void enqueueCusto()
{
    if(rear==MAX_CUSTO-1)
        printf("Delivery queue full!\n");
    else
    {
        int CUSTO;
        printf("Enter Customer ID: ");
        scanf("%d", &CUSTO);
        if(front==-1)
            front=0;
        rear++;
        custoQueue[rear]=CUSTO;
        printf("Customer %d added.\n", CUSTO);
    }
}


int dequeueCusto()
{
    if(front==-1||front>rear)
    {
        printf("No customers waiting!\n");
        return -1;
    }
    int CUSTO=custoQueue[front];
    front++;
    if(front>rear)
        front=rear=-1;
    return CUSTO;
}


void peekCusto()
{
    if(front==-1||front>rear)
        printf("No customers waiting!\n");
    else
        printf("Next customer to deliver: %d\n", custoQueue[front]);
}

void displayCusto()
{
    if(front==-1||front>rear)
    {
        printf("No customers waiting.\n");
        return;
    }
    printf("Customers in queue (Front to Rear):\n");
    for(int i=front; i<=rear; i++)
    printf("%d\n", custoQueue[i]);
}
