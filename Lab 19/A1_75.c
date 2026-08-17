#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

struct node *create_node(int info)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->info = info;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert_node(int info, struct node *root)
{
    if (root == NULL)
    {
        root = create_node(info);
        return root;
    }
    else
    {
        if (root->info < info)
        {
            root->right = insert_node(info, root->right);
            return root;
        }
        else
        {
            root->left = insert_node(info, root->left);
            return root;
        }
    }
}

struct node* find_min(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node *delete_node(int info, struct node *root)
{
    if (root == NULL)
    {
        printf("info not found.\n");
        return NULL;
    }

    if (info < root->info)
    {
        root->left = delete_node(info, root->left);
    }
    else if (info > root->info)
    {
        root->right = delete_node(info, root->right);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = find_min(root->right);
            root->info = temp->info;
            root->right = delete_node(temp->info, root->right);

            //as per sir's method
            // struct node *temp1 = find_min(root->right);
            // temp1->left = root->left;

            // free(root);
            // return temp1->right;
            

        }
    }

    return root;
}



void search_node(int info, struct node *root)
{
    if (root == NULL)
    {
        printf("\ninfo not found.\n");
    }
    else if (root->info == info)
    {
        printf("%d info found", info);
    }
    else
    {
        if (root->info < info)
        {
            search_node(info, root->right);
        }
        else
        {
            search_node(info, root->left);
        }
    }
}

void inorder_traversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder_traversal(root->left);
        printf("%d ,", root->info);
        inorder_traversal(root->right);
    }
}

void preorder_traversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ,", root->info);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ,", root->info);
    }
}

void main()
{
    struct node *root = NULL;
    int choice, info;

    while (1)
    {
        printf("\n---- Binary Search Tree Menu ----\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Search Node\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter info to insert: ");
            scanf("%d", &info);
            root = insert_node(info, root);
            break;

        case 2:
            printf("Enter info to delete: ");
            scanf("%d", &info);
            root = delete_node(info, root);
            break;

        case 3:
            printf("Enter info to search: ");
            scanf("%d", &info);
            search_node(info, root);
            break;

        case 4:
            printf("Inorder: ");
            inorder_traversal(root);
            printf("\n");
            break;

        case 5:
            printf("Preorder: ");
            preorder_traversal(root);
            printf("\n");
            break;

        case 6:
            printf("Postorder: ");
            postorder_traversal(root);
            printf("\n");
            break;

        case 7:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}