//Write a program to determine if an input character string is of the form aibi where i >= 1 i.e., Number of ‘a’ should be equal to number of ‘b’
#include <stdio.h>
#include <string.h>
void main(){
    char str[100];
    int count_a = 0, count_b = 0;
    printf("Enter a string: ");
    scanf("%s", str);
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == 'a'){
            count_a++;
        } else if(str[i] == 'b'){
            count_b++;
        } else {
            printf("Invalid character found. Only 'a' and 'b' are allowed.\n");
            return;
        }
    }
    if(count_a == count_b && count_a > 0){
        printf("The string is of the form aibi where i >= 1.\n");
    } else {
        printf("The string is not of the form aibi where i >= 1.\n");
    }
}