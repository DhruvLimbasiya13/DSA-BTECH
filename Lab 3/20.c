#include<stdio.h>

int isDuplicate(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return 1; // Duplicate found
            }
        }
    }
    return 0; // No duplicates
}

void main(){
    int total_Numbers;

    printf("Enter the total numbers: ");
    scanf("%d", &total_Numbers);

    int numbers[total_Numbers];
    for (int i = 0; i < total_Numbers; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    if(isDuplicate(numbers, total_Numbers)){
        printf("Duplicate numbers found.\n");
    } else {
        printf("No duplicate numbers found.\n");
    }
}