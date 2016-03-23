/*
	Xu XuTao
	create : unknown
	modify : 2016, 3, 23
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	QUEUE_H should be added
*/


struct Queue
{
    void **base;
    int head;
    int rear;
    int maxSize;
}; 



int queue_is_empty(struct Queue *arg);
void queue_in(struct Queue *arg, void *element);
void* queue_out(struct Queue *arg);
void queue_destory(struct Queue *arg);
void queue_init(struct Queue *arg, int maxSize);
