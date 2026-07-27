#include <stdio.h>
#include <string.h>

#define max 100
char stack[max];
int top = -1;

int input_precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 3;
    else if (c == '^')
        return 6;
    else if (c == '(')
        return 9;
    else if (c == ')')
        return 0;
    else
        return 7;
}

int stack_precedence(char c)
{
    if (c == '+' || c == '-')
        return 2;
    else if (c == '*' || c == '/')
        return 4;
    else if (c == '^')
        return 5;
    else if (c == '(')
        return 0;
    else
        return 8;
}

int r(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return -1;
    else
        return 1;
}

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

void convert_to_postfix(char infixstring[])
{
    int i = 0;
    char postfixstring[max];
    int rank = 0;
    int j = 0;
    push('(');
    while (i != strlen(infixstring))
    {
        char next = infixstring[i];
        if (top < 0)
        {
            printf("Invalid Expression.");
            return;
        }
        while (stack_precedence(stack[top]) > input_precedence(next))
        {
            char temp = pop();
            postfixstring[j++] = temp;
            rank = rank + r(temp);
            if (rank < 1)
            {
                printf("Invalid Expression");
                return;
            }
        }

        if (stack_precedence(stack[top]) != input_precedence(next))
        {
            push(next);
        }
        else
        {
            char temp = pop();
        }
        i++;
    }
    postfixstring[j] = '\0';
    if(top!=-1 || rank != 1)
        printf("Invalid");
    else{
        printf("%s", postfixstring);
    }
}

void main()
{
    char infixstring[max];
    printf("enter the infix string :");
    scanf("%s", infixstring);
    strcat(infixstring ,")");
    convert_to_postfix(infixstring);
}