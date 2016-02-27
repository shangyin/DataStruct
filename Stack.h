#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack
{
    void *base;
    int top;
    int maxSize;
    int elemSize;
};


void initStack(struct Stack *arg, int maxSize, int elemSize);
void pushStack(struct Stack *arg, void* element);
void* popStack(struct Stack *arg);
void* peekStack(struct Stack *arg);
void DestroyStack(struct Stack *arg);
int isEmptyStack(struct Stack *arg);
