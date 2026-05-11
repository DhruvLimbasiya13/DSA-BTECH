#include <stdio.h>
#include <string.h>

int isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void reverseSubstring(char *s, int end)
{
    int start = 0;
    while (start < end)
    {
        char temp = s[start];
        s[start] = s[end - 1];
        s[end - 1] = temp;
        start++;
        end--;
    }
}

void main()
{
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d", &t);

    while (t--)
    {

        char s[100];
        printf("Enter the string: ");
        scanf("%s", s);

        for (int i = 0; i < strlen(s); i++)
        {
            if (isVowel(s[i]))
            {
                reverseSubstring(s, i);
            }
        }

        printf("%s\n", s);
    }
}