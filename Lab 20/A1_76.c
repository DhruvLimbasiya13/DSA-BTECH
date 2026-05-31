#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
};

void insert(struct Node **root, int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*root == NULL)
    {
        *root = newNode;
        return;
    }

    struct Node *current = *root;
    struct Node *parent = NULL;

    while (current != NULL)
    {
        parent = current;
        if (data < current->info)
            current = current->left;
        else
            current = current->right;
    }

    if (data < parent->info)
        parent->left = newNode;
    else
        parent->right = newNode;
}

void delete(struct Node **root, int data){
    if (*root == NULL)
        return;

    if (data < (*root)->info)
        delete(&(*root)->left, data);
    else if (data > (*root)->info)
        delete(&(*root)->right, data);
    else
    {
        if ((*root)->left == NULL)
        {
            struct Node *temp = *root;
            *root = (*root)->right;
            free(temp);
        }
        else if ((*root)->right == NULL)
        {
            struct Node *temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        else
        {
            struct Node *temp = (*root)->right;
            while (temp->left != NULL){
                temp = temp->left;
            }

            (*root)->info = temp->info;
            delete(&(*root)->right, temp->info);
        }
    }
}

void search(struct Node *root, int data){
    if (root == NULL)
    {
        printf("Element not found\n");
        return;
    }

    if (data < root->info)
        search(root->left, data);
    else if (data > root->info)
        search(root->right, data);
    else
        printf("Element found\n");
}

void inorder(struct Node *root){
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

void preorder(struct Node *root){
    if (root != NULL)
    {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root){
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

void main()
{
    int choice;
    struct Node *root = NULL;
    int data;

    while (1)
    {
        printf("1. Insert\n2. Delete\n3. Search\n4. inorder\n5. preorder\n6. postorder\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            insert(&root, data);
            break;
        case 2:
            printf("Enter the data to delete: ");
            scanf("%d", &data);
            delete(&root, data);
            break;
        case 3:
            printf("Enter the data to search: ");
            scanf("%d", &data);
            search(root, data);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            preorder(root);
            break;
        case 6:
            postorder(root);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}