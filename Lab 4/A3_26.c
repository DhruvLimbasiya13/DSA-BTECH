//Write a program to insert a number in an array that is already sorted in an ascending order.

#include<stdio.h>
void main(){
    int total_elements , number;

    printf("Enter the total number of elements in the array: ");
    scanf("%d", &total_elements);

    int arr[total_elements + 1];

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

    printf("Enter the number you want to insert: ");
    scanf("%d", &number);

    for (int i = 0; i < total_elements + 1; i++)
    {
        if (number < arr[i]) {
            for (int j = total_elements; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            arr[i] = number;
            break;
        }
    }
    

    for (int i = 0; i < total_elements + 1; i++) {
        printf("element %d: %d\n", i + 1, arr[i]);
    }
}