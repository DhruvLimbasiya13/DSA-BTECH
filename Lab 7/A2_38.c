#include<stdio.h>
#include<string.h>
void main(){
    char user_stirng[100];
    printf("Enter A string :");
    scanf("%s", user_stirng);

    int len = strlen(user_stirng);
    char stack[len];
    int top = -1;

    for(int i=0 ; i<len ; i++){
        if(user_stirng[i] == '*'){
            top--;
        }else{
            stack[++top] = user_stirng[i];
        }
    }

    for (int i = 0; i < top + 1; i++)
    {
        printf("%c", stack[i]);
    }
    
}