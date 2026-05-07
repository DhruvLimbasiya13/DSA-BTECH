//WAP to convert seconds into hours, minutes & seconds and print in HH:MM:SS
//[e.g. 10000 seconds mean 2:46:40 (2 Hours, 46 Minutes, 40 Seconds)]
#include<stdio.h>
void main()
{
    int totalSeconds, hours, minutes, seconds;
    printf("Enter total seconds: ");
    scanf("%d", &totalSeconds);
    hours = totalSeconds / 3600;
    minutes = (totalSeconds % 3600) / 60;
    seconds = totalSeconds % 60;
    printf("Time in HH:MM:SS format: %02d:%02d:%02d\n", hours, minutes, seconds);
}