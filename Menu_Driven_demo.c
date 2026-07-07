#include<stdio.h>
#include<stdlib.h>
void main()
{

    int choice;
    while(1){
        printf("Enter your choice:\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                //insert front
                break;
            case 2:
                //insert rear
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