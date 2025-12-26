#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleLinkedList
{
    struct DoubleLinkedList *prev;
    struct DoubleLinkedList *next;
    int value;
} DoubleLinkedList;

DoubleLinkedList *createLinkedList(int value)
{
    DoubleLinkedList *linkedList = (DoubleLinkedList *) malloc(sizeof(DoubleLinkedList));
    
    if (linkedList == NULL)
    {
        free(linkedList);
        exit(1);
    }

    linkedList->prev = NULL;
    linkedList->next = NULL;
    linkedList->value = value;
}

void add(DoubleLinkedList *l, int value)
{
    while (l->next = NULL)
    {
        l = l->next;
    }
    l->next = createLinkedList(value);
    l->next->prev = l;
}

DoubleLinkedList *addFirst(DoubleLinkedList *l, int value)
{
    DoubleLinkedList *newHead = createLinkedList(value);
    newHead->next = l;
    l->prev = newHead;

    return newHead;
}

int pop(DoubleLinkedList *l, int index)
{
    for (int i=0; i<index; i++)
    {
        if (l->next == NULL)
        {
            printf("Index %d dosent exixts\n", index);
            return -1;
        }
        l = l->next;
    }

    l->prev = l->next;

    return l->value;
}

DoubleLinkedList *removeFirst(DoubleLinkedList *l)
{
    l = l->next;
    l->prev = NULL;

    return l;
}

void printLinkedList(DoubleLinkedList *l)
{
    DoubleLinkedList *next = l->next;
    printf("%d <-> ", l->value);

    while (next != NULL)
    {
        printf("%d <-> ", next->value);
        next = next->next;
    }
    printf("\n");
}

int main()
{
    DoubleLinkedList *dl = createLinkedList(1);
    add(dl, 2);
    add(dl, 3);

    printLinkedList(dl);

    dl = addFirst(dl, 9);

    printLinkedList(dl);

    dl = removeFirst(dl);

    pop(dl, 1);

    printLinkedList(dl);

    return 0;
}