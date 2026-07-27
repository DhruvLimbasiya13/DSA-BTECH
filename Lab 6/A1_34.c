#include <stdio.h>
#include <stdlib.h>
void main(){
    int *ptr_int;
    char *ptr_char;
    float *ptr_float;

    // Allocating memory for int, char and float variable
    ptr_int = (int *)malloc(sizeof(int));
    ptr_char = (char *)malloc(sizeof(char));
    ptr_float = (float *)malloc(sizeof(float));

    // Check if memory allocation was successful
    if (ptr_int == NULL || ptr_char == NULL || ptr_float == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Assigning values to the allocated memory
    *ptr_int = 42;
    *ptr_char = 'A';
    *ptr_float = 3.14f;

    // Printing the values
    printf("Integer value: %d\n", *ptr_int);
    printf("Character value: %c\n", *ptr_char);
    printf("Float value: %.2f\n", *ptr_float);

    // De-allocating memory
    free(ptr_int);
    free(ptr_char);
    free(ptr_float);
}