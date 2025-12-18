#include <stdio.h>
#include <stdlib.h>

/* Binary Tree Node */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* Create a new node */
struct node* createNode(int val)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Preorder Traversal: Root -> Left -> Right */
void preorder(struct node* root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

/* Inorder Traversal: Left -> Root -> Right */
void inorder(struct node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* Postorder Traversal: Left -> Right -> Root */
void postorder(struct node* root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    /* Tree creation */
    struct node* root = createNode(10);

    root->left = createNode(5);
    root->right = createNode(15);

    root->left->left = createNode(2);
    root->left->right = createNode(7);

    root->right->left = createNode(12);
    root->right->right = createNode(20);

    /* Traversals */
    printf("Preorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}
