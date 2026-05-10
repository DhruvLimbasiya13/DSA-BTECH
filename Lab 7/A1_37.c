#include <stdio.h>
#include <string.h>
void main()
{
    char user_string[100];
    printf("Enter A string :");
    scanf("%s", user_string);

    int top = -1;
    int len = strlen(user_string);
    char stack[len];

    int flag = 1;

    for (int i = 0; i < len; i++)
    {
        char temp = user_string[i];
        if (temp == '(' || temp == '{' || temp == '[')
        {
            stack[++top] = temp;
        }
        else if (temp == ')' || temp == '}' || temp == ']')
        {
            if (top == -1)
            {
                flag = 0;
            }

            char stack_top = stack[top--];
            if ((temp == ')' && stack_top != '(') || (temp == '}' && stack_top != '{') || (temp == ']' && stack_top != '['))
            {
                flag = 0;
            }
        }
    }

    if ( (flag == 1) && (top == -1) )
        printf("Entered String is Balanced. ");
    else
        printf("Entered String is Not Balanced. ");
}