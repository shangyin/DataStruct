/*
	Xu XuTao
	create : unknown
	modify : 2016, 3, 26
	note : well checked
*/

#include <stdio.h>
#include "Array.h"

int ArrayMain(void)
{
	int sum[] = { 1,2,3,4,5,6,7,8,9 };
	struct Array tmp;
	int *ret;
	int *ret2;
	int *ret3;
	int *ret4;

	array_init(&tmp, 128);
	
	/* add an element and get it */
	array_insert_rear(&tmp, sum);
	ret = array_get_head(&tmp);
	printf("%d(should be 1)\n", *ret);
	
	/* array is 2 1 3 */
	array_insert_head(&tmp, sum + 1);
	array_insert_rear(&tmp, sum + 2);
	ret2 = array_get_rear(&tmp);
	printf("%d (should be 3)\n", *ret2);

	/* array is 4 1 3 */
	array_set_by_index(&tmp, sum + 3, 0);
	ret3 = array_get_head(&tmp);
	printf("%d(should be 4)\n", *ret3);

	/* array is 1 3 */
	array_remove_head(&tmp);
	printf("%d(should be 2)\n", array_get_length(&tmp));

	while (!array_is_empty(&tmp))
	{
		ret4 = array_get_head(&tmp);
		printf("%d ", *ret4);
		array_remove_head(&tmp);
	}
	printf("(should be 1 3)\n");
	return 0;
}