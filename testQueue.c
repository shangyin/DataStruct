#include "Queue.h"
#include <stdio.h>

int main(void)
{
    struct Queue tmp;
    int i;

    initQueue(&tmp, 10, sizeof(int));
    for (i = 0; i < 8; i++)
    {
        inQueue(&tmp, &i);
    }
    while (!isEmptyQueue(&tmp))
    {
        int *ret = deQueue(&tmp);
        printf("%d\n", *ret);
    }
    return 0;
    
}
