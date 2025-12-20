#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue 
{
    size_t length;
    int capacity;
    int tail;
    int head;
    int *data;
} CircularQueue;

CircularQueue *createQueue(size_t length)
{
    CircularQueue *q = (CircularQueue *) malloc(sizeof(CircularQueue));

    if (q == NULL)
    {
        free(q);
        exit(1);
    }

    q->length = length;
    q->data = (int *) malloc(sizeof(int) * q->length);

    if (q->data == NULL)
    {
        free(q->data);
        free(q);
        exit(1);
    }

    q->head, q->tail = 0;
    q->capacity = q->length;

    return q;
}

void freeQueue(CircularQueue *q)
{
    free(q->data);
    free(q);
}

int isFull(CircularQueue *q)
{
    return q->capacity == 0;
}

int isEmpty(CircularQueue *q)
{
    return q->capacity == q->length;
}

void enqueue(CircularQueue *q, int value)
{
    if (!isFull(q))
    {
        q->data[q->tail++%q->length] = value;
        q->capacity--;
        return;
    }
    printf("Queue is full!\n");
    return;
}

int dequeue(CircularQueue *q)
{
    if(!isEmpty(q))
    {
        int value = q->data[q->head];
        q->data[q->head] = 0;
        q->head = ++q->head%q->length;
        q->capacity++;

        return value;
    }
    printf("Queue is empty!");

    return -1;
}

void printQueue(CircularQueue *q)
{
    printf("{%d, ", q->data[0]);
    for (int i=1; i<q->length-1; i++)
    {
        printf("%d, ", q->data[i]);
    }
    printf("%d}\n", q->data[q->length-1]);
}

int main()
{
    CircularQueue *q = createQueue(3);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    dequeue(q);
    enqueue(q, 4);
    
    printQueue(q);

    freeQueue(q);
    return 0;
}