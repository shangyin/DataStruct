#include "Stack.h"

void initStack(struct Stack *arg, int maxSize, int elemSize)
{
    /* should check whether returns NULL */
    arg->base = malloc(maxSize*elemSize);
    arg->top = 0;
    arg->maxSize = maxSize;
    arg->elemSize = elemSize;
}

void pushStack(struct Stack *arg, void* element)
{
    if (arg->top >= arg->maxSize)
    {
        fprintf(stderr, "use full stack\n");
        return;
    }
    memcpy((arg->base)+(arg->top*arg->elemSize), element, arg->elemSize);
    arg->top++;
}

void* popStack(struct Stack *arg)
{
    if (arg->top == 0)
    {
        fprintf(stderr, "pop empty stack\n");
        return NULL;
    }
    arg->top -= 1;
    return (arg->base) + (arg->top * arg->elemSize);
}

void* peekStack(struct Stack *arg)
{
    return (arg->base) + ((arg->top-1) * arg->elemSize);
}

void DestroyStack(struct Stack *arg)
{
    free(arg->base);
}

int isEmptyStack(struct Stack *arg)
{
    return !arg->top; 
}
