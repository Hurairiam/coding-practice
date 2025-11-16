#include<stdio.h>
#include<stdlib.h>

int *stack;
int top=-1;
int MAX;

void push()
{
    if(top==MAX-1)
    {printf("Stack Overflow!\n");}
    else
    {
        int value;
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top]=value;
        printf("%d pushed into stack.\n", value);
    }
}

int pop()
{
    if(top==-1)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        int value=stack[top];
        top--;
        return value;
    }
}

void display()
{
    if(top==-1)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    for(int i=top; i>=0; i--)
    printf("%d ", stack[i]);

    printf("\n");
}

int main()
{
    printf("Enter the stack size: ");
    scanf("%d", &MAX);

    stack=(int*)malloc(MAX*sizeof(int));
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
printf("\t|    STACK MENU     |\n");
printf("\t=====================\n\n");
printf("\t1. Push\n");
printf("\t2. Pop\n");
printf("\t3. Display\n");
printf("\t4. Exit\n\n");
printf("\tEnter your choice: ");
scanf("%d", &choice);

system("cls");

switch(choice)
    {
    case 1:
    {
        push();
        break;
    }

    case 2:
    {
        int val=pop();
        if(val!=-1)
          {printf("Popped: %d\n", val);}
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

