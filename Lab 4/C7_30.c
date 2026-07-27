// Replace lowercase letters with uppercase and uppercase letters with lowercase.
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main(){
    int length;
    
    // Read the number of strings to process.
    printf("Enter the total number of strings: ");
    scanf("%d", &length);

    // Store each input string in a fixed-size buffer.
    char str[length][100];

    // Read all strings from the user.
    for (int i = 0; i < length; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", str[i]);
    }

    // Toggle the case of every alphabetic character in each string.
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < strlen(str[i]); j++) {
            if(islower(str[i][j])) {
                str[i][j] = toupper(str[i][j]);
            }
            else if (isupper(str[i][j])) {
                str[i][j] = tolower(str[i][j]);
            }
        }
    }

    // Print the updated strings.
    for (int i = 0; i < length; i++) {
        printf("String %d: %s\n", i + 1, str[i]);
    }
}