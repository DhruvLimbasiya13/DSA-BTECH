#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void insertAtEnd(struct Node **first){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node) );
    scanf("%d", &newNode->data);
    newNode -> next = NULL;
    if(*first == NULL){
        *first = newNode;
    }
    else{
        struct Node *temp = *first;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}

void copyList(struct Node *first){
    if(first == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *newList = NULL;
    struct Node *temp = first;
    while(temp != NULL){
        insertAtEnd(&newList);
        newList->data = temp->data;
        temp = temp -> next;
    }
    printf("Copied list: ");
    display(newList);
}

void display(struct Node *first){
    if(first == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *temp = first;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void main(){
    //first
    struct Node *first = NULL;
    int choice;
    while(1){
        printf("1. Insert\n2. Display\n3. Copy List\n4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insertAtEnd(&first);
                break;
            case 2:
                display(first);
                break;
            case 3:
                copyList(first);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}