#include <stdio.h>
#include<stdlib.h>

#define SIZE 10

int top = -1;
int stack[SIZE];

void push();
void pop();
void print();

int main()
{
    int option;
    while(1)
    {
        printf("1.push\n2.pop\n3.print\n4.exit\n");
        printf("Enter option: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: print();
            break;
            case 4: exit(0);
            break;
        }
    }
}
void push()
{
    int num;
    printf("Enter the element to be inserted: ");
    scanf("%d", &num);
    if(top == SIZE-1)
    {
        printf("Stack is full\n");
    }
    else
    {
        stack[++top] = num;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Deleted element is %d\n", stack[top]);
        top--;
    }
}

void print()
{
    for(int i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
