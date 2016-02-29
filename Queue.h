#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Queue
{
    void **base;
    int head;
    int rear;
    int maxSize;
}; 



int isEmptyQueue(struct Queue *arg);
void inQueue(struct Queue *arg, void *element);
void* deQueue(struct Queue *arg);
void destroyQueue(struct Queue *arg);
void initQueue(struct Queue *arg, int maxSize);
