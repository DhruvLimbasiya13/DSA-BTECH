// Write a program to delete a number from an array that is already sorted in an ascending order.

#include<stdio.h>
void main(){
    int total_elements , number;

    printf("Enter the total number of elements in the array: ");
    scanf("%d", &total_elements);

    int arr[total_elements];

    for (int i = 0; i < total_elements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    //bubble sort
    for (int i = 0; i < total_elements - 1; i++) {
        for (int j = 0; j < total_elements - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Enter the number you want to delete: ");
    scanf("%d", &number);

    for (int i = 0; i < total_elements; i++) {
        if (arr[i] == number) {
            for (int j = i; j < total_elements - 1; j++) {
                arr[j] = arr[j + 1];
            }
            total_elements--;
            break;
        }
    }

    for (int i = 0; i < total_elements; i++) {
        printf("element %d: %d\n", i + 1, arr[i]);
    }
}