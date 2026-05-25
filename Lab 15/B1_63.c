#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

void insert(struct Node **first, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->info = data;
    newNode->link = NULL;

    if (*first == NULL)
    {
        *first = newNode;
    }
    else
    {
        struct Node *temp = *first;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = newNode;
    }
}

void deleteNode(struct Node **first, int data)
{
    struct Node *temp = *first;
    struct Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->info == data)
        {
            if (prev == NULL)
            {
                *first = temp->link;
            }
            else
            {
                prev->link = temp->link;
            }

            free(temp);
            printf("Node deleted\n");
            return;
        }

        prev = temp;
        temp = temp->link;
    }

    printf("Data not found\n");
}

void sort_list(struct Node *first)
{
    if (first == NULL)
    {
        return;
    }

    struct Node *current = first;

    while (current != NULL)
    {
        struct Node *index = current->link;

        while (index != NULL)
        {
            if (current->info > index->info)
            {
                int temp = current->info;
                current->info = index->info;
                index->info = temp;
            }

            index = index->link;
        }

        current = current->link;
    }
}

void remove_duplicates(struct Node *first)
{
    struct Node *current = first;

    while (current != NULL && current->link != NULL)
    {
        if (current->info == current->link->info)
        {
            struct Node *temp = current->link;
            current->link = temp->link;
            free(temp);
        }
        else
        {
            current = current->link;
        }
    }
}

void display(struct Node *first)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = first;

    while (temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }

    printf("NULL\n");
}

int main()
{
    int choice, data;
    struct Node *first = NULL;

    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Remove Duplicate\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insert(&first, data);
            break;

        case 2:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            deleteNode(&first, data);
            break;

        case 3:
            sort_list(first);
            remove_duplicates(first);
            printf("Duplicates removed\n");
            break;

        case 4:
            display(first);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

}