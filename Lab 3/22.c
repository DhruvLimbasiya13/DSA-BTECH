//    1
//   1 1
//  1 2 1
// 1 3 3 1
#include<stdio.h>
void main(){
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows - i - 1; j++)
        {
            printf(" ");
        }
        int number = 1;
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", number);
            number = number * (i - j) / (j + 1);
        }
        printf("\n");
    }
}