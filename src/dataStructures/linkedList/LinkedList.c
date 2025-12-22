#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    int value;
    struct LinkedList *next;
} LinkedList;

LinkedList *createNode(int value)
{
    LinkedList *node = malloc(sizeof(LinkedList));

    if (node == NULL)
    {
        free(node);
        exit(1);
    }

    node->value = value;
    node->next = NULL;
    
    return node;
}

void freeLinkedList(LinkedList *self)
{
    if (self->next != NULL) {
        return freeLinkedList(self->next);
    }
    free(self);
    
    return;
}

void add(LinkedList *self, int value)
{
    while (self->next != NULL)
    {
        self = self->next;
    }

    self->next = createNode(value);
}

LinkedList *addFirst(LinkedList *self, int value)
{
    LinkedList *newHead = createNode(value);
    newHead->next = self;

    return newHead;
}

int pop(LinkedList *self, int index)
{
    LinkedList *prev = self;

    for (int i=0; i<index; i++)
    {
        if (self->next == NULL)
        {
            printf("Index %d dosent exixts\n", index);
            return -1;
        }
        prev = self;
        self = self->next;
    }

    prev->next = self->next;

    return self->value;
}

void printLinkedList(LinkedList *self)
{
    LinkedList *next = self->next;
    printf("%d -> ", self->value);

    while (next != NULL)
    {
        printf("%d -> ", next->value);
        next = next->next;
    }
}

int main()
{
    LinkedList *head = createNode(4);
    add(head, 3);
    add(head, 1);

    head = addFirst(head, 4);

    pop(head, 3);

    printLinkedList(head);
    
    freeLinkedList(head);
    
    return 0;
}