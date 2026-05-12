#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
int enqueue(int arr[], int *top, int total_elements)
{
    if (*top == total_elements - 1)
    {
        printf("Queue is full\n");
        return -1;
    }
    int element;
    printf("Enter the element to enqueue: ");
    scanf("%d", &element);
    (*top)++;
    arr[*top] = element;
    return 0;
}
int dequeue(int arr[], int *top)
{
    if (*top == -1)
    {
        printf("Queue is empty\n");
        return false;
    }
    int element = arr[0];
    for (int i = 0; i < *top; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*top)--;
    return element;
}
void display(int arr[], int top)
{
    if (top == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main()
{
    int total_elements;
    printf("Enter the total number of elements: ");
    scanf("%d", &total_elements);

    int arr[total_elements];
    int top = -1;

    char choice;

    while (1)
    {

        printf("Enter Your choice: \n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            enqueue(arr, &top, total_elements);
            break;
        case '2':
            int element = dequeue(arr, &top);
            if(element != false)
                printf("Dequeued element: %d\n", element);
            break;
        case '3':
            display(arr, top);
            break;
        case '4':
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}