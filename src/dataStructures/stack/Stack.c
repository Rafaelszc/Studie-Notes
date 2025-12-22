#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    size_t size;
    int top;
    int *data;
} Stack;

Stack *createStack(size_t size)
{
    Stack *stack = (Stack *) malloc(sizeof(Stack));

    if (stack == NULL)
    {
        free(stack);
        exit(1);
    }

    stack->size = size;
    stack->data = (int *) malloc(stack->size*sizeof(int));
    stack->top = -1;

    if (stack->data == NULL)
    {
        free(stack->data);
        free(stack);
        exit(1);
    }

    return stack;
}

void freeStack(Stack *s)
{
    free(s->data);
    free(s);
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == s->size-1;
}

void push(Stack *s, int value)
{
    if (!isFull(s))
    {
        s->data[++s->top] = value;
        return;
    }
    printf("Stack overflow!\n");
    return;
}

int pop(Stack *s)
{
    if (!isEmpty(s))
    {
        int value = s->data[s->top];
        s->data[s->top--] = 0;

        return value;
    }
    printf("Stack undeflow!\n");
    return -1;
}

void printStack(Stack *s)
{
    printf("{%d, ", s->data[0]);

    for (int i=1; i<s->size-1; i++)
    {
        printf("%d, ", s->data[i]);
    }

    printf("%d}\n", s->data[s->size-1]);
}

int main()
{
    Stack *stack = createStack(5);

    push(stack, 4);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printStack(stack);

    pop(stack);
    printStack(stack);

    freeStack(stack);

    return 0;
}