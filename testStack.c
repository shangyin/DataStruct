/*
	Xu XuTao
	create : unknown
	modify : 2016, 3, 26
	note : well checked
*/

#include "Stack.h"
#include <stdio.h>

int StackMain(void)
{
    int i;
    struct Stack sample;
    stack_init(&sample, 10);
    for (i = 0; i < 5; i++)
    {
        stack_push(&sample, &i);
    }
    while (!stack_is_empty(&sample))
    {
        int *tmp = stack_pop(&sample);
        printf("%d\n", *tmp);		/* the output should 43210 */
    }
    return 0;
}
