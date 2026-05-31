#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int info;
    struct Node *right;
    struct Node *left;
};

void insert(struct Node **root, int data)
{
    if (*root == NULL)
    {
        *root = (struct Node *)malloc(sizeof(struct Node));
        (*root)->info = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (data < (*root)->info)
    {
        insert(&(*root)->left, data);
    }
    else
    {
        insert(&(*root)->right, data);
    }
}

void delete(struct Node **root, int data)
{
    if (*root == NULL)
    {
        printf("Data not found.\n");
        return;
    }

    if (data < (*root)->info)
    {
        delete(&(*root)->left, data);
    }
    else if (data > (*root)->info)
    {
        delete(&(*root)->right, data);
    }
    else
    {
        // Node to be deleted found
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
            // Node with two children
            struct Node *temp = (*root)->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            (*root)->info = temp->info;
            delete(&(*root)->right, temp->info);
        }
    }
}

int isMirror(struct Node *t1, struct Node *t2)
{
    if (t1 == NULL && t2 == NULL)
        return 1;
    if (t1 == NULL || t2 == NULL)
        return 0;
    return (t1->info == t2->info) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

int Check_for_Symmetric(struct Node *root1)
{
    if (root1 == NULL)
        return 1;
    return isMirror(root1->left, root1->right);
}

void main()
{
    struct Node *root = NULL;

    int choice, data;

    while (1)
    {
        printf("1. insert\n2. delete\n3. check if trees are symmetric\n4. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter data to insert in tree 1: ");
            scanf("%d", &data);
            insert(&root, data);
            break;
        case 2:
            printf("enter data to delete from tree: ");
            scanf("%d", &data);
            delete(&root, data);
            break;
        case 3:
            if (Check_for_Symmetric(root))
            {
                printf("The tree is symmetric.\n");
            }
            else
            {
                printf("The tree is not symmetric.\n");
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}