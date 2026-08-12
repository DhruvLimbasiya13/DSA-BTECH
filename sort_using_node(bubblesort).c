#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

void insertAtEnd(struct Node **first, int info)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->info = info;
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

void deleteNode(struct Node **first, int info)
{
    struct Node *temp = *first;
    struct Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->info == info)
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

    printf("info not found\n");
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

int countNodes(struct Node *first)
{
    int count = 0;
    struct Node *temp = first;

    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }

    return count;
}

void bubbleSort(struct Node **first)
{
    if (*first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    int n = countNodes(*first);

    for (int i = 0; i < n - 1; i++)
    {
        struct Node *prev = NULL;
        struct Node *curr = *first;

        for (int j = 0; j < n - i - 1; j++)
        {
            struct Node *link = curr->link;

            if (link != NULL && curr->info > link->info)
            {
                if (prev == NULL)
                {
                    *first = link;
                }
                else
                {
                    prev->link = link;
                }

                curr->link = link->link;
                link->link = curr;

                prev = link;
            }
            else
            {
                prev = curr;
                curr = curr->link;
            }

            if (prev != link)
            {
                curr = prev->link;
            }
        }
    }

    printf("List sorted successfully using bubble sort\n");
}

int main(void)
{
    int choice;
    int info;
    struct Node *first = NULL;

    while (1)
    {
        printf("1. Insert\n2. Delete\n3. Sort\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the info to be inserted: ");
            scanf("%d", &info);
            insertAtEnd(&first, info);
            break;
        case 2:
            printf("Enter the info to be deleted: ");
            scanf("%d", &info);
            deleteNode(&first, info);
            break;
        case 3:
            bubbleSort(&first);
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

    return 0;
}