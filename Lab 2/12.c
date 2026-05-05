//WAP to check whether a number is prime or not.
#include<stdio.h>
#include<stdbool.h>
// can return 1 or 0 instead of true or false, but using bool makes it more readable and easier to understand
int isPrime(int number){
    for(int i = 2 ; i <= (number/2)+1 ; i++){
        if(number % i == 0){
            return false;
        }
    }
    return true;
}
void main(){
    int number ;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (isPrime(number))
    {
        printf("%d is Prime Number.", number);
    }
    else{
        printf("%d is Not Prime Number.", number);
    }
}