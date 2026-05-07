//How stack can be used to recognize strings aca, bcb, abcba, abbcbba? Write a program to solve the above problem.
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void main()
{
    char stack[MAX_SIZE];
    int top = -1;

    char input_string[MAX_SIZE];
    int i = 0;
    int is_valid = 1;

    printf("Enter a string (e.g., aca, bcb, abcba): ");
    scanf("%s", input_string);

    int length = strlen(input_string);
    int middle_index = -1;

    for (i = 0; i < length; i++)
    {
        if (input_string[i] == 'c')
        {
            middle_index = i;
            break;
        }
    }

    if (middle_index == -1)
    {
        is_valid = 0;
    }
    else
    {
        for (i = 0; i < middle_index; i++)
        {
            if (top < MAX_SIZE - 1)
            {
                top++;
                stack[top] = input_string[i];
            }
            else
            {
                printf("Error: Stack Overflow. The input string is too long.\n");
                return;
            }
        }

        for (i = middle_index + 1; i < length; i++)
        {
            if (top == -1)
            {
                is_valid = 0;
                break;
            }

            char popped_char = stack[top];
            top--;

            if (popped_char != input_string[i])
            {
                is_valid = 0;
                break;
            }
        }

        if (top != -1)
        {
            is_valid = 0;
        }
    }

    if (is_valid)
    {
        printf("Result: The string \"%s\" is accepted.\n", input_string);
    }
    else
    {
        printf("Result: The string \"%s\" is rejected.\n", input_string);
    }
}