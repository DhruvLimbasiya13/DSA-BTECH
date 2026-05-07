//WAP to find power of a number using loop.
#include <stdio.h>
void main()
{
    int base, power;

    printf("Enter the Base number :");
    scanf("%d", &base);

    printf("Enter the Power of Base number :");
    scanf("%d", &power);

    if (power == 0)
    {
        printf("answer : 1");
        return;
    }

    int answer = 1;

    for (int i = 1; i <= power; i++)
    {
        answer *= base;
    }

    printf("%d ^ %d : %d" , base , power , answer);
}