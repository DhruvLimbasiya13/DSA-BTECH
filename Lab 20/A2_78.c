#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int info)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int info)
{
    if (root == NULL)
        return createNode(info);
    int choice;
    printf("Insert %d to left(1) or right(2) of %d? ", info, root->info);
    scanf("%d", &choice);
    if (choice == 1)
        root->left = insert(root->left, info);
    else
        root->right = insert(root->right, info);
    return root;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int isBalanced(struct Node *root)
{
    if (root == NULL)
        return 1;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1)
        return 0;
    return isBalanced(root->left) && isBalanced(root->right);
}

void main()
{
    struct Node *root = NULL;
    int choice, val;
    while (1)
    {
        printf("\n1. Insert Node");
        printf("\n2. Check if Balanced");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            if (root == NULL)
                root = createNode(val);
            else
                root = insert(root, val);
            break;
        case 2:
            if (isBalanced(root))
                printf("The tree is height-balanced.\n");
            else
                printf("The tree is NOT height-balanced.\n");
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
