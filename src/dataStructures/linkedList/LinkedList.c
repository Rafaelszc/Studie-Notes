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

void add(LinkedList *node, int value)
{
    while (node->next != NULL)
    {
        node = node->next;
    }

    node->next = createNode(value);
}

LinkedList *addFirst(LinkedList *node, int value)
{
    LinkedList *newHead = createNode(value);
    newHead->next = node;

    return newHead;
}

int pop(LinkedList *node, int index)
{
    LinkedList *prev = node;

    for (int i=0; i<index; i++)
    {
        if (node->next == NULL)
        {
            printf("Index %d dosent exixts\n", index);
            return -1;
        }
        prev = node;
        node = node->next;
    }

    prev->next = node->next;

    return node->value;
}

void printLinkedList(LinkedList *node)
{
    LinkedList *next = node->next;
    printf("%d -> ", node->value);

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

    return 0;
}