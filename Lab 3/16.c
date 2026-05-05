#include<stdio.h>
void main(){
    int total_Numbers;

    printf("Enter the total numbers: ");
    scanf("%d", &total_Numbers);

    int numbers[total_Numbers];
    for(int i = 0; i < total_Numbers; i++){
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < total_Numbers; i++)
    {
        printf("Number %d: %d\n", i + 1, numbers[i]);
    }
    
}