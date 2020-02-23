#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 5
#define MIN_SIZE 0
#define SUCCESS 1
#define FAIL 0

typedef struct queue
{
    int queue[MAX_SIZE];
    int front;
    int rear;

}queue_t;

int peek(queue_t* p);
int is_full(queue_t* p);
int is_empty(queue_t* p);

int enqueue(queue_t* p, int value);
int dequeue(queue_t* p);

int main(void)
{
    queue_t my_queue = {{1, 2, 3}, 0, 2};
    printf("First queue front value: %d\n", peek(&my_queue));
    printf("Is the first queue full: %d\n\n", is_full(&my_queue));

    printf("enqueue to first queue: %d\n", enqueue(&my_queue, 4));
    printf("enqueue to first queue: %d\n", enqueue(&my_queue, 5));
    printf("enqueue to first queue: %d\n", enqueue(&my_queue, 6));
    printf("First queue front value: %d\n", peek(&my_queue));
    printf("Is the first queue full: %d\n\n", is_full(&my_queue));

    queue_t my_queue_2 = {{}, -1, -1};
    printf("Second queue front value:  %d\n", peek(&my_queue_2));
    printf("Is the second queue empty: %d\n\n", is_empty(&my_queue_2));

    printf("enqueue to second queue: %d\n", enqueue(&my_queue_2, 5));
    printf("Second queue front value:  %d\n", peek(&my_queue_2));
    printf("Is the second queue empty: %d\n\n", is_empty(&my_queue_2));

    printf("dequeue to second queue: %d\n", dequeue(&my_queue_2));
    printf("Second queue front value:  %d\n", peek(&my_queue_2));
    printf("Is the second queue empty: %d\n\n", is_empty(&my_queue_2));


    return 0;
}

int peek(queue_t* p)
{
    return p->queue[p->front];
}

int is_full(queue_t* p)
{
    return (p->rear >= MAX_SIZE-1) ? TRUE: FALSE;
}

int is_empty(queue_t* p)
{
    return (p->front < MIN_SIZE || p->front > p->rear ) ? TRUE: FALSE;
}

int enqueue(queue_t* p, int value)
{
    if(is_full(&(*p)) == TRUE)
        return FAIL;
    else
    {
        p->rear += 1;
        p->queue[p->rear] = value;
        if(p->front < MIN_SIZE)
            p->front = MIN_SIZE;
        return SUCCESS;
    }
}
int dequeue(queue_t* p)
{
    if(is_empty(&(*p)) == TRUE)
        return FAIL;
    else
    {
        p->front += 1;
        return SUCCESS;
    }
}
