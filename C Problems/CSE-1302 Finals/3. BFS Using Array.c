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

#define MAX 100
struct node* queue[MAX];
int front = 0, rear = 0;

void enqueue(struct node* n) {
    if (rear == MAX) {
        printf("Queue Overflow!\n");
        return;
    }
    queue[rear++] = n;
}

struct node* dequeue() {
    if (front == rear) {
        printf("Queue Underflow!\n");
        return NULL;
    }
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void BFS(struct node* root) {
    if (root == NULL) return;

    front = rear = 0;
    enqueue(root);

    printf("BFS (Level Order): ");
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

int main() {
    struct node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(20);

    BFS(root);

    return 0;
}
