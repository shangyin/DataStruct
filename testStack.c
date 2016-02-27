#include "Stack.h"
#include <stdio.h>

int main(void)
{
    int i;
    struct Stack sample;
    initStack(&sample, 10, sizeof(int));
    for (i = 0; i < 5; i++)
    {
        pushStack(&sample, &i);
    }
    while (!isEmptyStack(&sample))
    {
        int *tmp = popStack(&sample);
        printf("%d\n", *tmp);
    }
    return 0;
    
}
