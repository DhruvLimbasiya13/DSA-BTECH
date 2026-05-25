// Write a program to implement queue using singly linked list.
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct Node
{
    int info;
    struct Node *link;
};

void enqueue(struct Node **front, struct Node **rear, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->info = data;
    temp->link = NULL;
    if (*rear == NULL)
    {
        *front = *rear = temp;
        return;
    }
    (*rear)->link = temp;
    *rear = temp;
}

int dequeue(struct Node **front, struct Node **rear)
{
    if (*front == NULL)
    {
        printf("Queue underflow\n");
        return false;
    }
    struct Node *temp = *front;
    *front = (*front)->link;
    if (*front == NULL)
        *rear = NULL;
    int data = temp->info;
    free(temp);
    return data;
}

void display(struct Node *front)
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

void main()
{
    int choice, data;
    struct Node *front = NULL, *rear = NULL;
    while (1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(&front, &rear, data);
            break;
        case 2:
            int data = dequeue(&front, &rear);
            printf("Dequeued data: %d\n", data);
            break;
        case 3:
            display(front);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}