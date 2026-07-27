// Insert a number at a given location in an array by shifting later elements to the right.
#include <stdio.h>

void main(){
    int total_elements, location, number;

    // Read the current size of the array.
    printf("Enter the total number of elements in the array: ");
    scanf("%d", &total_elements);

    // Create one extra slot so the new element can be inserted.
    int arr[total_elements+1];

    // Read the existing elements from the user.
    for (int i = 0; i < total_elements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Ask for the 1-based position where the new number should be inserted.
    printf("Enter the location where you want to insert the number (1 to %d): ", total_elements + 1);
    scanf("%d", &location);

    // Read the value to be inserted.
    printf("Enter the number you want to insert: ");
    scanf("%d", &number);

    // Shift elements one step to the right to make room for the new value.
    for (int i = total_elements; i > location - 1; i--) {
        arr[i] = arr[i - 1];
    }

    // Place the new number at the requested location.
    arr[location - 1] = number;

    // Print the updated array.
    for (int i = 0; i < total_elements + 1; i++) {
        printf("element %d: %d\n", i + 1, arr[i]);
    }

}