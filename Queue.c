


/*	the queue only store the pointer of elements.
	so, should NOT use the elements from the queue which has been free already.
*/


#include "Queue.h"

void initQueue(struct Queue *arg, int maxSize)
{
    /* shoud check NULL */
    arg->base = malloc((maxSize+1)*sizeof(void*));
    arg->head = arg->rear = 0;
    arg->maxSize = maxSize + 1;     /* left one for check */
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
	(arg->base)[arg->head] = element;
    arg->head = (arg->head + 1) % arg->maxSize;
}

void* deQueue(struct Queue *arg)
{
    if (arg->head == arg->rear)
    {
        fprintf(stderr, "deQueue empty queue\n");
        return NULL;
    }
	void *tmp = (arg->base)[arg->rear];
    arg->rear = (arg->rear + 1) % arg->maxSize;
    return tmp;
}

void destroyQueue(struct Queue *arg)
{
    free(arg->base);
}
