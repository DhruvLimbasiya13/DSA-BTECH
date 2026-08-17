#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int info;
    struct Node *left;
    struct Node *right;
};

void insert(struct Node **root, int info){
    int choice;
    if(*root == NULL){
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->info = info;
        newNode->left = NULL;
        newNode->right = NULL;
        *root = newNode;
        return;
    }
    printf("Current node info: %d\n", (*root)->info);
    printf("1. Insert in left subtree\n2. Insert in right subtree\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if(choice == 1){
        insert(&((*root)->left), info);
    } else if(choice == 2){
        insert(&((*root)->right), info);
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

bool check_same(struct Node *root1, struct Node *root2){
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL || root1->info != root2->info)
    {
        printf("Trees are not the same\n");
        return false;
    }

    return check_same(root1->left, root2->left) && check_same(root1->right, root2->right);
}

void main(){
    int choice;
    struct Node *root1 = NULL;
    struct Node *root2 = NULL;

    int data;
    while(1){
        printf("1.insert in tree 1\n2.insert in tree 2\n3.check for same\n4.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data to insert in tree 1: ");
                scanf("%d", &data);
                insert(&root1, data);
                break;
            case 2:
                printf("Enter data to insert in tree 2: ");
                scanf("%d", &data);
                insert(&root2, data);
                break;
            case 3:
                if (check_same(root1, root2))
                    printf("Trees are the same\n");
                else
                    printf("Trees are not the same\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
