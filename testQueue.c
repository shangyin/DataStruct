/*
	Xu XuTao
	create : unknown
	modify : 2016, 3, 23
	note : well checked
*/
#include "Queue.h"
#include <stdio.h>

int main(void)
{
    struct Queue tmp;
    int i;

    queue_init(&tmp, 10);
    for (i = 0; i < 8; i++)
    {
        queue_in(&tmp, &i);
    }
    while (!queue_is_empty(&tmp))
    {
        int *ret = queue_out(&tmp);
        printf("%d\n", *ret);	/* the output should be 01234567 */
    }
    return 0;
    
}
