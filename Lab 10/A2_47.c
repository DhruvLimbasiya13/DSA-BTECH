#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int insert(int arr[], int *top, int total_elements, int element){
    if (*top == total_elements - 1)
    {
        *top = -1;
    }
    (*top)++;
    arr[*top] = element;
    return 0;
}

int delete(int arr[], int *first, int total_elements){
    if (*first == -1)
    {
        printf("Queue is empty\n");
        return false;
    }
    int element = arr[*first];
    (*first)++;
    if(*first == total_elements){
        *first = 0;
    }
    return element;
}

void display(int arr[], int first, int top, int total_elements){
    if (first == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = first;
    while (i != top)
    {
        printf("%d ", arr[i]);
        i++;
        if(i == total_elements){
            i = 0;
        }
    }
    printf("%d\n", arr[top]);
}
void main(){
    int total_elements;
    printf("Enter the total number of elements: ");
    scanf("%d", &total_elements);

    int arr[total_elements];
    int top = -1;
    int first = 0;

    int choice;

    while (1)
    {
        printf("Enter your choice\n1. Insert\n2. Delete \n3. Display \n4. Exit\n");
        scanf(" %d", &choice);

        switch(choice){
            case 1:
                int element;
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insert(arr, &top, total_elements, element);
                break;
            case 2:
                int element;
                element = delete(arr, &first, total_elements);
                if(element != false){
                    printf("Deleted element: %d\n", element);
                }
                break;
            case 3:
                display(arr, first, top, total_elements);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}