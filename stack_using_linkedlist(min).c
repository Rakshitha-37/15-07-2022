#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}stack;

void getmin(stack **top_arg);

void push(stack **top_arg, int data)
{
    stack *new = (stack *)malloc(sizeof(stack));
    if(new == NULL)
    {
        printf("Memory allocation failed\n");
    }
    else
    {
        new->data = data;
        new->link = NULL;
        if(*top_arg == NULL)
        {
            *top_arg = new;
        }
        else
        {
            new->link = *top_arg;
            *top_arg = new;
        }
        printf("Inserted element is %d\n", new->data);
    }
}

int peek(stack **top_arg)
{
    stack *temp = *top_arg;
    return temp->data;
}

void pop(stack **top_arg)
{
    if(*top_arg == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        stack *temp = *top_arg;
        *top_arg = temp->link;
        printf("Deleted element is %d\n", temp->data);
        free(temp);
        getmin(&(*top_arg));
    }
}

void getmin(stack **top_arg)
{
    if(*top_arg == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        stack *temp = *top_arg;
        int min = temp->data;
        while(temp != NULL)
        {
            if(temp->data < min)
            {
                min = temp->data;
            }
            temp = temp->link;
        }
        printf("Minimum element is : %d\n", min);
    }
}

void display(stack **top_arg)
{
    if(*top_arg == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        stack *temp = *top_arg;
        printf("Stack elements are: ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main()
{
    stack *top = NULL;
    int option, data;
    while(1)
    {
     printf("1. Push\n2. Pop\n3. display\n4. Exit\nEnter option: ");
     scanf("%d", &option);
     switch(option)
     {
        case 1: printf("Enter data: ");
        scanf("%d", &data);
        push(&top, data);
        break;
        case 2: pop(&top);
        break;
        case 3: display(&top);
        break;
        case 4: exit(0);
        break;
        default: printf("Invalid option\n");
        break;
     }
    }
    
    return 0;
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
