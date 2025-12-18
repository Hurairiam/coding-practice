#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Node structure */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* Create a new node */
struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* ----------------- BFS ----------------- */
struct node* queue[MAX];
int front = 0, rear = 0;

void enqueue(struct node* n) {
    queue[rear] = n;
    rear = (rear + 1) % MAX;
}

struct node* dequeue() {
    struct node* n = queue[front];
    front = (front + 1) % MAX;
    return n;
}

int isEmpty() {
    return front == rear;
}

void BFS(struct node* root) {
    if (root == NULL) return;

    front = rear = 0;
    enqueue(root);

    printf("BFS Traversal: ");
    while (!isEmpty()) {
        struct node* current = dequeue();
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(current->left);
        if (current->right != NULL)
            enqueue(current->right);
    }
    printf("\n");
}

/* ----------------- DFS ----------------- */
struct node* stack[MAX];
int top = -1;

void push(struct node* n) {
    if (top < MAX - 1)
        stack[++top] = n;
}

struct node* pop() {
    if (top >= 0)
        return stack[top--];
    return NULL;
}

int isStackEmpty() {
    return top == -1;
}

void DFS(struct node* root) {
    if (root == NULL) return;

    top = -1;
    push(root);

    printf("DFS (Preorder) Traversal: ");
    while (!isStackEmpty()) {
        struct node* current = pop();
        printf("%d ", current->data);

        if (current->right != NULL)
            push(current->right);
        if (current->left != NULL)
            push(current->left);
    }
    printf("\n");
}

/* ----------------- Main ----------------- */
int main() {
    struct node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(20);

    BFS(root);
    DFS(root);

    return 0;
}

