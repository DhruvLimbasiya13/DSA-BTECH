// Write a program to determine if an input character string is of the form aibi where i >= 1 i.e., Number of ‘a’ should be equal to number of ‘b’. using stack
#include <stdio.h>
#include <string.h>
void main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);
    char stack[100];
    int top = -1;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'a')
        {
            stack[++top] = 'a';
        }
        else if (str[i] == 'b')
        {
            if (top == -1)
            {
                printf("The string is not of the form aibi where i >= 1.\n");
                return;
            }
            top--;
        }
        else
        {
            printf("Invalid character found. Only 'a' and 'b' are allowed.\n");
            return;
        }
    }
    if (top == -1)
    {
        printf("The string is of the form aibi where i >= 1.\n");
    }
    else
    {
        printf("The string is not of the form aibi where i >= 1.\n");
    }
}