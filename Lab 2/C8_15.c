// WAP to print Armstrong number from 1 to 1000.
#include<stdio.h>
#include<math.h>
int digits(int number){
    int count = 0;
    while(number){
        count++;
        number /= 10;
    }
    return count;
}

int isArmstrong(int number){
    int sum = 0 , temp = number;
    int number_Of_Digits = digits(number);
    while(temp){
        int last_Digit = temp % 10;
        sum += pow(last_Digit , number_Of_Digits);
        temp /= 10;
    }

    return sum == number;
}

void main(){
    int number;

    printf("Enter a number between 1 to 1000 :");
    scanf("%d",&number);

    if(isArmstrong(number)){
        printf("%d is an Armstrong Number." , number);
    }
    else{
        printf("%d is Not an Armstrong Number." , number);
    }
}