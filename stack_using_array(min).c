#include <stdio.h>
#include<stdlib.h>

#define SIZE 10
int top = -1;
int stack[SIZE];

void push();
void pop();
void print();
void getmin();

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
        getmin();
    }
}

void getmin()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        int min = stack[top];
        for(int i = top-1;i >= 0;i--)
        {
            if(stack[i] < min)
            {
                min = stack[i];
            }
        }
        printf("Minimum element = %d\n", min);
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


Expected output:

push() -> 7
push() -> 33
push() -> 5
push() -> 10
push() -> 3
push() -> 100
push() -> 25
pop() -> 25 getmin() -> 3
pop() -> 100 getmin() -> 3
pop() -> 3 getmin() -> 5

