#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int val) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

/* Stack for DFS */
#define MAX 100
struct node* stack[MAX];
int top = -1;

void push(struct node* n) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = n;
}

struct node* pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return NULL;
    }
    return stack[top--];
}

int isEmptyStack() {
    return top == -1;
}

/* DFS Iterative */
void DFS(struct node* root) {
    if (root == NULL) return;

    top = -1;
    push(root);

    printf("DFS (Preorder Iterative): ");
    while (!isEmptyStack()) {
        struct node* current = pop();
        printf("%d ", current->data);

        if (current->right != NULL)
            push(current->right);
        if (current->left != NULL)
            push(current->left);
    }
    printf("\n");
}

/* Main */
int main() {
    struct node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(20);

    DFS(root);

    return 0;
}

