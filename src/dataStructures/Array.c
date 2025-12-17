#include <stdio.h>
#include <stdlib.h>

typedef struct Array
{
    size_t length;
    int *arr;
    void (*set) (struct Array *self, int *values);
} Array;

void set(Array *arr, int *values)
{
    for (int i=0; i<arr->length; i++)
    {
        arr->arr[i] = values[i];
    }
}

Array *alloc_array(size_t length)
{
    Array *arr = (Array *) malloc(sizeof(Array));

    if (arr == NULL)
    {
        exit(1);
    }

    arr->arr = (int *) malloc(sizeof(int) * length);
    if (arr->arr == NULL)
    {
        free(arr->arr);
        free(arr);
        exit(1);
    }

    arr->set = set;
    arr->length = length;

    return arr;
}


void print_array(Array *arr)
{
    printf("{");

    for (int i=0; i<arr->length-1; i++)
    {
        printf("%d, ", arr->arr[i]);
    }

    printf("%d}\n", arr->arr[arr->length-1]);
}

int main()
{
    Array *arr = alloc_array(5);
    arr->set(arr, (int[]) {1, 2, 3, 4, 5});

    print_array(arr);
    
    free(arr->arr);
    free(arr);

    return 0;
}