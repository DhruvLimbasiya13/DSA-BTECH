//Write a program to merge two unsorted arrays.
#include<stdio.h>
void main(){
    int total_elements1, total_elements2;

    printf("Enter the total number of elements in the first array: ");
    scanf("%d", &total_elements1);

    printf("Enter the total number of elements in the second array: ");
    scanf("%d", &total_elements2);

    int arr1[total_elements1];
    int arr2[total_elements2];
    int merged_arr[total_elements1 + total_elements2];

    printf("Enter elements of the first array:\n");
    for (int i = 0; i < total_elements1; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    printf("Enter elements of the second array:\n");
    for (int i = 0; i < total_elements2; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    // Merge the two arrays
    for (int i = 0; i < total_elements1; i++) {
        merged_arr[i] = arr1[i];
    }
    for (int i = 0; i < total_elements2; i++) {
        merged_arr[total_elements1 + i] = arr2[i];
    }

    printf("Merged array:\n");
    for (int i = 0; i < total_elements1 + total_elements2; i++) {
        printf("Element %d: %d\n", i + 1, merged_arr[i]);
    }
}