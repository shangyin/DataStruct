#include "Queue.h"

void initQueue(struct Queue *arg, int maxSize, int elemSize)
{
    /* shoud check NULL */
    arg->base = malloc((maxSize+1) * elemSize);
    arg->head = arg->rear = 0;
    arg->maxSize = maxSize + 1;     /* left one for check */
    arg->elemSize = elemSize;
}

int isEmptyQueue(struct Queue *arg)
{
    return arg->head == arg->rear;
}

void inQueue(struct Queue *arg, void *element)
{
    if ((arg->head+1) % arg->maxSize == arg->rear)
    {
        fprintf(stderr, "inQueue full queue\n");
        return;
    }
    memcpy((arg->base)+(arg->head*arg->elemSize), element, arg->elemSize);
    arg->head = (arg->head + 1) % arg->maxSize;
}

void* deQueue(struct Queue *arg)
{
    if (arg->head == arg->rear)
    {
        fprintf(stderr, "deQueue empty queue\n");
        return NULL;
    }
    void* tmp = (arg->base) + (arg->rear * arg->elemSize);
    arg->rear = (arg->rear + 1) % arg->maxSize;
    return tmp;
}

void destroyQueue(struct Queue *arg)
{
    free(arg->base);
}
