#include<stdio.h>
#include<stdlib.h>

void insert_front(int double_queue[], int *front, int *rear, int total_elements){
    //move front to the left
    if(*front == 0){
        printf("Queue is full. Cannot insert at front.\n");
        return;
    }

    int element;
    *front = (*front - 1 + total_elements) % total_elements;
    printf("Enter the element to insert at front: ");
    scanf("%d", &element);
    double_queue[*front] = element;
    if(*rear == -1){
        *rear = *front;
    }
}

void insert_rear(int double_queue[], int *front, int *rear, int total_elements){
    //move rear to the right
    if((*rear + 1) % total_elements == *front){
        printf("Queue is full. Cannot insert at rear.\n");
        return;
    }

    int element;
    printf("Enter the element to insert at rear: ");
    scanf("%d", &element);
    *rear = (*rear + 1) % total_elements;
    double_queue[*rear] = element;
    if(*front == -1){
        *front = *rear;
    }
}

int delete_front(int double_queue[], int *front, int *rear, int total_elements){
    if(*front == -1){
        printf("Queue is empty. Cannot delete from front.\n");
        return -1;
    }

    int element = double_queue[*front];
    if(*front == *rear){
        *front = -1;
        *rear = -1;
    } else {
        *front = (*front + 1) % total_elements;
    }
    return element;
}

int delete_rear(int double_queue[], int *front, int *rear, int total_elements){
    if(*rear == -1){
        printf("Queue is empty. Cannot delete from rear.\n");
        return -1;
    }

    int element = double_queue[*rear];
    if(*front == *rear){
        *front = -1;
        *rear = -1;
    } else {
        *rear = (*rear - 1 + total_elements) % total_elements;
    }
    return element;
}

void display(int double_queue[], int front, int rear, int total_elements){
    if(front == -1){
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in the queue: ");
    for(int i = front; i != rear; i = (i + 1) % total_elements){
        printf("%d ", double_queue[i]);
    }
    printf("%d\n", double_queue[rear]);
}
void main()
{
    int total_elements;
    printf("Enter the total number of elements in the queue: ");
    scanf("%d", &total_elements);
    int double_queue[total_elements];
    int front = -1, rear = -1;

    int choice;
    while(1){
        printf("Enter your choice:\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insert_front(double_queue, &front, &rear, total_elements);
                break;
            case 2:
                insert_rear(double_queue, &front, &rear, total_elements);
                break;
            case 3:
                //delete front
                break;
            case 4:
                //delete rear
                break;
            case 5:
                //display
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}