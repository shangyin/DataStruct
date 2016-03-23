/*
	Xu XuTao
	create : unknown
	modify : 2016, 3, 23
	note : well checked
*/

#include "Queue.h"

void queue_init(struct Queue *arg, int maxSize)
{
    arg->base = malloc((maxSize+1)*sizeof(void*));
	if (!arg->base)
	{
		fprintf(stderr, "malloc returns NULL\n");
	}
    arg->head = arg->rear = 0;
    arg->maxSize = maxSize + 1;     /* left one for check */
}

int queue_is_empty(struct Queue *arg)
{
    return arg->head == arg->rear;
}

void queue_in(struct Queue *arg, void *element)
{
    if ((arg->head+1) % arg->maxSize == arg->rear)
    {
        fprintf(stderr, "inQueue full queue\n");
        return;
    }
	(arg->base)[arg->head] = element;
    arg->head = (arg->head + 1) % arg->maxSize;
}

void* queue_out(struct Queue *arg)
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

void queue_destory(struct Queue *arg)
{
    free(arg->base);
}
