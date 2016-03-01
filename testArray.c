#include <stdio.h>
#include "Array.h"

int main(void)
{
	int sum[] = { 1,2,3,4,5,6,7,8,9 };
	struct Array tmp;
	int *ret;
	int *ret2;
	int *ret3;
	int *ret4;

	initArray(&tmp, 128);
	
	InsertArrayRear(&tmp, sum);
	ret = getArrayHead(&tmp);
	printf("%d(should be 1)\n", *ret);
	
	InsertArrayHead(&tmp, sum + 1);
	InsertArrayRear(&tmp, sum + 2);
	ret2 = getArrayRear(&tmp);
	printf("%d (should be 3)\n", *ret2);

	modifyArrayByIndex(&tmp, sum + 3, 0);
	ret3 = getArrayHead(&tmp);
	printf("%d(should be 4)\n", *ret3);

	removeArrayHead(&tmp);
	printf("%d(should be 2)\n", getArrayLength(&tmp));

	while (!isArrayEmpty(&tmp))
	{
		ret4 = getArrayHead(&tmp);
		printf("%d ", *ret4);
		removeArrayHead(&tmp);
	}
	printf("(should be 1 3)\n");
	return 0;
}