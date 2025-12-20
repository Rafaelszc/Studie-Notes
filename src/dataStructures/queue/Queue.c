#include <stdio.h>
#include <stdlib.h>

typedef struct Queue 
{
    size_t length;
    int tail;
    int head;
    int* data;
} Queue;

Queue* createQueue(size_t length)
{
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    if (queue == NULL)
    {
        free(queue);
        exit(1);
    }

    queue->length = length;
    queue->tail = 0;
    queue->head = 0;
    queue->data = (int *) malloc(sizeof(int)*length);

    if (queue->data == NULL)
    {
        free(queue->data);
        free(queue);
        exit(1);
    }

    return queue;
}

void freeQueue(Queue *q)
{
    free(q->data);
    free(q);
}

int isFull(Queue *q)
{
    return q->tail == q->length;
}

int isEmpty(Queue *q)
{
    return q->head == q->tail;
}

int enqueue(Queue *q, int value)
{
    if (!isFull(q))
    {
        q->data[q->tail++] = value;
        printf("%d enqueued\n", value);
        return 1;
    }
    printf("Queue is full!\n");

    return 0;
}

void enqueueMany(Queue *q, int* values)
{
    for (int i=0; i<=(sizeof(values)); i++)
    {
        if (!enqueue(q, values[i])) return;
    }
}

int dequeue(Queue* q)
{
    if (!isEmpty(q))
    {
        int value = q->data[q->head++];
        q->data[q->head-1] = 0;
        printf("%d dequeued\n", value);
        return value;
    }
    printf("Queue is empty!\n");
}

void printQueue(Queue *q)
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
    Queue *queue = createQueue(5);
    
    int values[6] = {1, 2, 4, 5, 3, 3};

    enqueue(queue, 3);
    enqueueMany(queue, values);
    printQueue(queue);
    
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    
    printQueue(queue);
    
    freeQueue(queue);
    
    return 0;
}