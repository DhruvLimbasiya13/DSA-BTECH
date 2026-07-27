#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAtEnd(struct Node **first, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*first == NULL)
    {
        *first = newNode;
    }
    else
    {
        struct Node *temp = *first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(struct Node **first, int data)
{
    struct Node *temp = *first;
    struct Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            if (prev == NULL)
            {
                *first = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);
            printf("Node deleted\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Data not found\n");
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
        printf("%d -> ", temp->data);
        temp = temp->next;
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
        temp = temp->next;
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
            struct Node *next = curr->next;

            if (next != NULL && curr->data > next->data)
            {
                if (prev == NULL)
                {
                    *first = next;
                }
                else
                {
                    prev->next = next;
                }

                curr->next = next->next;
                next->next = curr;

                prev = next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }

            if (prev != next)
            {
                curr = prev->next;
            }
        }
    }

    printf("List sorted successfully using bubble sort\n");
}

int main(void)
{
    int choice;
    int data;
    struct Node *first = NULL;

    while (1)
    {
        printf("1. Insert\n2. Delete\n3. Sort\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            insertAtEnd(&first, data);
            break;
        case 2:
            printf("Enter the data to be deleted: ");
            scanf("%d", &data);
            deleteNode(&first, data);
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