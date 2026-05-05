#include<stdio.h>
void main(){
    int starting_Number, ending_Number;

    printf("Enter the starting number: ");
    scanf("%d", &starting_Number);

    printf("Enter the ending number: ");
    scanf("%d", &ending_Number);

    int sum = 0;

    for (int i = starting_Number; i <= ending_Number; i++)
    {
        sum += i;
    }

    printf("Sum of numbers from %d to %d is: %d\n", starting_Number, ending_Number, sum);
}