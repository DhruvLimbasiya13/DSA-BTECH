// area of circle
#include<stdio.h>
#define PI 3.14159
void main()
{
    float radius, area;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    
    area = PI * radius * radius;
    
    printf("The area of the circle is: %.2f\n", area);
}