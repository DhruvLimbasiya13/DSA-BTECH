//whether the number is even or odd
#include <stdio.h>
void main()
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    if(num % 2 == 0)
        printf("%d is an even number.\n", num);
    else
        printf("%d is an odd number.\n", num);
}