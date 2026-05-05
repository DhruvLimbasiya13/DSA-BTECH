#include <stdio.h>
#include <string.h>

void main()
{
    int total_Names;

    printf("Enter the total names: ");
    scanf("%d", &total_Names);

    char names[total_Names][100];
    for (int i = 0; i < total_Names; i++)
    {
        printf("Enter name %d: ", i + 1);
        scanf("%s", names[i]);
    }

    // Sort the names in alphabetical order
    for (int i = 0; i < total_Names - 1; i++)
    {
        for (int j = 0; j < total_Names - i - 1; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                char temp[100];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("Names in alphabetical order:\n");
    for (int i = 0; i < total_Names; i++)
    {
        printf("%s\n", names[i]);
    }
}