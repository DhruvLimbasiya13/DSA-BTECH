// WAP to find the sum of 1 + (1+2) + (1+2+3) + (1+2+3+4)+ …+(1+2+3+4+….+n).
#include<stdio.h>

int result(int number){
    int result ;
    for(int i = 1 ; i<=number ; i++){
        for(int j = 1 ; j <= i ; j++){
            result += j;
        }
    }

    return result;
}

void main(){
    int number ;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Answer : %d" , result(number));
}