//WAP to replace lowercase characters by uppercase & vice-versa in a user specified string.
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main(){
    int length;
    
    printf("Enter the total number of strings: ");
    scanf("%d", &length);

    char str[length][100];

    for (int i = 0; i < length; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", str[i]);
    }

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
    for (int i = 0; i < length; i++) {
        printf("String %d: %s\n", i + 1, str[i]);
    }
}