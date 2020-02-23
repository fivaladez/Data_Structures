#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 5
#define MIN_SIZE 0
#define SUCCESS 1
#define FAIL 0

typedef struct stack
{
    int stack[MAX_SIZE];
    int top;

}stack_t;

int peek(stack_t* p);
int is_full(stack_t* p);
int is_empty(stack_t* p);

int push(stack_t* p, int value);
int pop(stack_t* p);

int main(void)
{
    stack_t my_stack = {{1, 2, 3}, 2};
    printf("First stack last value: %d\n", peek(&my_stack));
    printf("Is the first stack full: %d\n\n", is_full(&my_stack));

    printf("Push to first stack: %d\n", push(&my_stack, 4));
    printf("Push to first stack: %d\n", push(&my_stack, 5));
    printf("Push to first stack: %d\n", push(&my_stack, 6));
    printf("First stack last value: %d\n", peek(&my_stack));
    printf("Is the first stack full: %d\n\n", is_full(&my_stack));

    stack_t my_stack_2 = {{}, -1};
    printf("Second stack last value:  %d\n", peek(&my_stack_2));
    printf("Is the second stack empty: %d\n\n", is_empty(&my_stack_2));

    printf("Push to second stack: %d\n", push(&my_stack_2, 5));
    printf("Second stack last value:  %d\n", peek(&my_stack_2));
    printf("Is the second stack empty: %d\n\n", is_empty(&my_stack_2));

    printf("Pop to second stack: %d\n", pop(&my_stack_2));
    printf("Second stack last value:  %d\n", peek(&my_stack_2));
    printf("Is the second stack empty: %d\n\n", is_empty(&my_stack_2));


    return 0;
}

int peek(stack_t* p)
{
    return p->stack[p->top];
}

int is_full(stack_t* p)
{
    return (p->top >= MAX_SIZE-1) ? TRUE: FALSE;
}

int is_empty(stack_t* p)
{
    return (p->top < MIN_SIZE) ? TRUE: FALSE;
}

int push(stack_t* p, int value)
{
    if(is_full(&(*p)) == TRUE)
        return FAIL;
    else
    {
        p->top += 1;
        p->stack[p->top] = value;
        return SUCCESS;
    }
}
int pop(stack_t* p)
{
    if(is_empty(&(*p)) == TRUE)
        return FAIL;
    else
    {
        p->top -= 1;
        return SUCCESS;
    }
}
