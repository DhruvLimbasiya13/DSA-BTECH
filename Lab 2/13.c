// WAP to check whether a number is prime or not.
#include <stdio.h>
#include <stdbool.h>

int isPrime(int number)
{
    for (int i = 2; i <= (number / 2) + 1; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

void main()
{
    int starting_Number, ending_Number;
    printf("Enter a starting number: ");
    scanf("%d", &starting_Number);

    printf("Enter a starting number: ");
    scanf("%d", &ending_Number);

    printf("List of Prime Numbers :");
    for (int i = starting_Number; i <= ending_Number; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }
}