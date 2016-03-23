/********************************************/
/*		Xu XuTao	2016,2,29				*/
/********************************************/

/*	
 *	the stack only store the pointer of elements.
 *	so, should NOT use the elements from the stack which has been free already.
 */

#include "Stack.h"

void stack_init(struct Stack *arg, int maxSize)
{
    /* should check whether returns NULL */
    arg->base = malloc(maxSize*sizeof(void*));
    arg->top = 0;
    arg->maxSize = maxSize;
}

void stack_push(struct Stack *arg, void* element)
{
    if (arg->top >= arg->maxSize)
    {
        fprintf(stderr, "use full stack\n");
        return;
    }
	(arg->base)[arg->top++] = element;
}

void* stack_pop(struct Stack *arg)
{
    if (arg->top == 0)
    {
        fprintf(stderr, "pop empty stack\n");
        return NULL;
    }
    arg->top -= 1;
	return (arg->base)[arg->top];
}

void* stack_peek(struct Stack *arg)
{
	return (arg->base)[arg->top - 1];
}

void stack_destroy(struct Stack *arg)
{
    free(arg->base);
}

int stack_is_empty(struct Stack *arg)
{
    return !arg->top; 
}

int main()
{
    while (1)
    {
        return 0;
    }
}