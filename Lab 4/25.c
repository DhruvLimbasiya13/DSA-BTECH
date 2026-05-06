//Write a program to delete a number from a given location in an array.
#include<stdio.h>
void main(){
    int total_elements, location;

    printf("Enter the total number of elements in the array: ");
    scanf("%d", &total_elements);

    int arr[total_elements];

    for (int i = 0; i < total_elements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the location from where you want to delete the number (1 to %d): ", total_elements);
    scanf("%d", &location);

    // Shift elements to the left
    for (int i = location - 1; i < total_elements - 1; i++) {
        arr[i] = arr[i + 1];
    }

    for (int i = 0; i < total_elements - 1; i++) {
        printf("element %d: %d\n", i + 1, arr[i]);
    }

}