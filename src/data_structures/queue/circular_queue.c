#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    size_t capacity;
    size_t size;
    int head;
    int tail;
    int *queue;
}CircularQueue;

CircularQueue **create_queues(int quantity)
{
    CircularQueue **queues = (CircularQueue **) malloc(quantity * sizeof(CircularQueue *));
    if(queues == NULL)
    {
        free(queues);
        exit(1);
    }

    for(int i=0; i<quantity; i++)
    {
        queues[i] = (CircularQueue *) malloc(sizeof(CircularQueue));
        queues[i]->head = 0;
        queues[i]->tail = -1;
        queues[i]->size = 0;

        if(queues[i] == NULL)
        {
            free(queues[i]);
        }
    }   

    return queues;
}

CircularQueue *alloc_queue(CircularQueue *q)
{
    q->queue = (int *) malloc(q->capacity * sizeof(int));

    if(q->queue == NULL)
    {
        free(q);
        exit(1);
    }

    return q;
}

void free_queues(CircularQueue **queues, int quantity)
{
    for(int i=0; i<quantity; i++)
    {
        free(queues[i]);
    }
    free(queues);
}

int is_empty(CircularQueue *q)
{
    return q->size == 0;
}

int is_full(CircularQueue *q)
{
    return q->size == q->capacity;
}

void enqueue(CircularQueue *q, int data)
{
    if(!is_full(q))
    {
        q->tail = (++q->tail) % (q->capacity);
        q->queue[q->tail] = data;
        q->size++;

        printf("%d Enqueued!\n", data);
    }

    else printf("%d cant be enqueued!\nQueue is full!!\n", data);
}

void dequeue(CircularQueue *q)
{
    if(!is_empty(q))
    {
        printf("%d Dequeued!\n", q->queue[q->head]);

        q->head = (++q->head) % (q->capacity);
        q->size--;
    }

    else printf("Queue is empty!\n");
}

void print_queue(CircularQueue *q)
{
    if(q->head <= q->tail)
    {
        for(int i=q->head; i<=q->tail; i++)
        {
            printf("%d ", q->queue[i]);
        }
    }
    else
    {
        for(int i=q->head; i<q->capacity; i++)
        {
            printf("%d ", q->queue[i]);
        }
        for(int i=0; i<=q->tail; i++)
        {
            printf("%d ", q->queue[i]);
        }
    }
    printf("\n");
}

int main()
{
    CircularQueue **queues = create_queues(2);

    queues[0]->capacity = 4;
    queues[1]->capacity = 3;

    queues[0] = alloc_queue(queues[0]);
    queues[1] = alloc_queue(queues[1]);

    enqueue(queues[0], 1);
    enqueue(queues[0], 2);
    enqueue(queues[0], 3);
    enqueue(queues[0], 4);
    enqueue(queues[0], 5);

    dequeue(queues[0]);

    enqueue(queues[0], 80);

    print_queue(queues[0]);

    enqueue(queues[1], 6);
    enqueue(queues[1], 4);
    enqueue(queues[1], 33);

    dequeue(queues[1]);
    dequeue(queues[1]);

    print_queue(queues[1]);

    free_queues(queues,2);

    return 0;
}