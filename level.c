#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    int level ;
    struct node * left;
    struct node * right;
};

struct node * createNode(int data) {
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = data;
    newNode->level = 0; // Initialize level to 0
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void setLevels(struct node *root, int count) {
    if (root == NULL) {
        return;
    }
    root->level = count;
    setLevels(root->left, count + 1);
    setLevels(root->right, count + 1);
}

//for binary tree
int get_level(struct node *root, int data) {
    if (root == NULL) {
        return -1; // Data not found
    }
    if (root->info == data) {
        return root->level;
    }
    int leftLevel = get_level(root->left, data);
    if (leftLevel != -1) {
        return leftLevel;
    }
    return get_level(root->right, data);
}

//for binary search tree
int get_level_bst(struct node *root, int data) {
    if (root == NULL) {
        return -1; // Data not found
    }
    if (root->info == data) {
        return root->level;
    }
    if (data < root->info) {
        return get_level_bst(root->left, data);
    } else {
        return get_level_bst(root->right, data);
    }
}

void main(){
    int choice, data;
    struct node *root = NULL;
    while(1) {
        printf("\n1. Insert\n2. Get Level\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = createNode(data);
                setLevels(root, 0); // Set levels after insertion
                break;
            case 2:
                printf("Enter data to find level: ");
                scanf("%d", &data);
                int level = get_level(root, data);
                if (level != -1) {
                    printf("Level of %d is %d\n", data, level);
                } else {
                    printf("%d not found in the tree.\n", data);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}