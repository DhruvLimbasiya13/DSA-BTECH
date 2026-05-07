
#include <stdio.h>
int top = -1;
int stack[20];
void push(int value)
{
    if (top == -1)
    {
        top = 0;
        stack[top] = value;
    }
    else if (top == 19)
    {
        printf("\nStack overflow.\n");
    }
    else
    {
        stack[top + 1] = value;
        top++;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("\nstack underflow.\n");
    }
    else
    {
        printf("\npopped element = %d\n", stack[top]);
        top--;
    }
}
void peep(int index)
{
    if (index > 19 || index < 0)
    {
        printf("\nindex invalid.\n");
    }
    else
    {
        int temp = top - index + 1;
        printf("\nvalue at index %d from top = %d \n", index, stack[temp]);
    }
}
void display()
{
    for (int i = top ; i >= 0 ; i--)
    {
        printf("%d ,", stack[i]);
    }
}

void change(int index, int value)
{
    int temp = top - index + 1;
    stack[temp] = value;
}

void main()
{
    int choice;
    while (1)
    {
        printf("\nEnter choice.\n1.push\n2.pop\n3.change\n4.peep.\n5.display\n6.exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int value;
            printf("\nenter value of element %d = ", top + 1);
            scanf("%d", &value);
            push(value);
            display();
            break;

        case 2:

            pop();
            display();
            break;

        case 3:
            int index;
            printf("\nenter index of element from top = ");
            scanf("%d", &index);
            printf("\nenter value of element you want to change = ");
            scanf("%d", &value);
            change(index, value);
            display();
            break;

        case 4:
            printf("\nenter index of element from top = ");
            scanf("%d", &index);
            peep(index);
            break;

        case 5:
            display();
            break;

        case 6:
            return;
            break;
        default:
            printf("\ninvalid choice.");
            break;
        }
    }
}