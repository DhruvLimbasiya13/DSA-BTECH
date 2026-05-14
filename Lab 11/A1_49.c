#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insert(int arr[][2], int *top, int total_elements, int element, int priority)
{
    if (*top == total_elements - 1)
    {
        printf("Queue is full\n");
        return;
    }
    (*top)++;
    arr[*top][0] = element;
    arr[*top][1] = priority;
    sort_queue_priority(arr, *top);
}

void sort_queue_priority(int arr[][2], int top)
{
    for (int i = 0; i < top; i++)
    {
        for (int j = 0; j < top - i; j++)
        {
            if (arr[j][1] < arr[j + 1][1]) // Higher priority first
            {
                int temp_element = arr[j][0];
                int temp_priority = arr[j][1];
                arr[j][0] = arr[j + 1][0];
                arr[j][1] = arr[j + 1][1];
                arr[j + 1][0] = temp_element;
                arr[j + 1][1] = temp_priority;
            }
        }
    }
}

int delete(int arr[][2], int *top)
{
    if (*top == -1)
    {
        printf("Queue is empty\n");
        return false;
    }
    int element = arr[0][0]; // Element with highest priority
    for (int i = 0; i < *top; i++)
    {
        arr[i][0] = arr[i + 1][0];
        arr[i][1] = arr[i + 1][1];
    }
    (*top)--;
    return element;
}

void display(int arr[][2], int top)
{
    if (top == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements (Element:Priority): ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d:%d ", arr[i][0], arr[i][1]);
    }
    printf("\n");
}

void main()
{
    int total_elements;
    printf("Enter the total number of elements: ");
    scanf("%d", &total_elements);

    int arr[total_elements][2]; // arr[element][priority]
    int top = -1;

    int choice;
    while (1)
    {
        printf("Enter your choice\n1. Insert with priority\n2. Delete \n3. Display \n4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int element, priority;
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            printf("Enter the priority for the element: ");
            scanf("%d", &priority);
            insert(arr, &top, total_elements, element, priority);
            break;
        case 2:
            int deleted_element = delete(arr, &top);
            if (deleted_element != false)            {
                printf("Deleted element: %d\n", deleted_element);
            }
            break;
        case 3:
            display(arr, top);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    }