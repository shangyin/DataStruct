/*
	Xu XuTao
	create : unknown
	modify : 2016.3.23 
	note : well checked
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	STACK_H should be added
*/

struct Stack
{
    void **base;
    int top;
    int maxSize;
};


void stack_init(struct Stack *arg, int maxSize);
void stack_push(struct Stack *arg, void* element);
void* stack_pop(struct Stack *arg);
void* stack_peek(struct Stack *arg);
void stack_destroy(struct Stack *arg);
int stack_is_empty(struct Stack *arg);
