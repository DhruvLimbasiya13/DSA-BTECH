//Write a program to delete duplicate numbers from an array.
#include<stdio.h>
void main(){
    int total_elements;

    printf("Enter the total number of elements in the array: ");
    scanf("%d", &total_elements);

    int arr[total_elements];
    for (int i = 0; i < total_elements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < total_elements; i++) {
        for (int j = i + 1; j < total_elements; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < total_elements - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                total_elements--;
                j--;
            }
        }
    }
    for (int i = 0; i < total_elements; i++) {
        printf("element %d: %d\n", i + 1, arr[i]);
    }
}