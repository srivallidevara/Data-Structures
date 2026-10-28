#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value)
{
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

/* Non-recursive Inorder */
void inorder(struct Node *root)
{
    struct Node *stack[100];
    int top = -1;
    struct Node *current = root;

    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);

        current = current->right;
    }
}

/* Non-recursive Preorder */
void preorder(struct Node *root)
{
    struct Node *stack[100];
    int top = -1;

    if (root == NULL)
        return;

    stack[++top] = root;

    while (top != -1)
    {
        struct Node *current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL)
            stack[++top] = current->right;

        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

/* Non-recursive Postorder */
void postorder(struct Node *root)
{
    struct Node *stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    struct Node *current;

    if (root == NULL)
        return;

    stack1[++top1] = root;

    while (top1 != -1)
    {
        current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL)
            stack1[++top1] = current->left;

        if (current->right != NULL)
            stack1[++top1] = current->right;
    }

    while (top2 != -1)
        printf("%d ", stack2[top2--]->data);
}

int main()
{
    struct Node *root = NULL;

    /* Fixed integers */
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n");

    return 0;
}