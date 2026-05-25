// Write a program to implement stack using singly linked list.
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct Node
{
    int info;
    struct Node *link;
};

void push(struct Node **top, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->info = data;
    temp->link = *top;
    *top = temp;
}

int pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack underflow\n");
        return false;
    }
    struct Node *temp = *top;
    *top = (*top)->link;
    int data = temp->info;
    free(temp);
    return data;
}

void display(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = top;
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
    struct Node *top = NULL;
    while (1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to push: ");
            scanf("%d", &data);
            push(&top, data);
            break;
        case 2:
            int data = pop(&top);
            printf("Popped data: %d\n", data);
            break;
        case 3:
            display(top);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }