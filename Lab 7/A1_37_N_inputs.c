#include <stdio.h>
#include <string.h>

#define MAX 1000 // maximum size for the stack

int isBalanced(char *s)
{
    char stack[MAX];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];

        // Push opening brackets
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack[++top] = ch;
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1)
                return 0; // stack empty but found closing bracket

            char topChar = stack[top--];

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '['))
            {
                return 0; // mismatch found
            }
        }
    }
    return (top == -1); // stack should be empty if balanced
}

int main()
{
    int T;
    printf("enter the total input you want :");
    scanf("%d", &T);

    while (T--)
    {
        char s[MAX];
        scanf("%s", s);

        if (isBalanced(s))
            printf("is balanced\n");
        else
            printf("is not balanced\n");
    }

    return 0;
}