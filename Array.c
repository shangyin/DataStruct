/************************************/
/*		Xu XuTao	2016,3,1		*/
/************************************/

/*
 *	the length of array is set when its init.
 *  the variable length version may be built in the future.
 */

/*
 * 	like python, offset == -1 means the last of array(maxSize + offset)
 */
 
#include "Array.h"

#define rightOffset(a,x) (x < 0 ? (((a->count+x)<0)?0:(a->count+x)) : x)


void initArray(struct Array *arg, int maxSize)
{
	arg->count = 0;
	arg->maxSize = maxSize;
	arg->base = malloc(sizeof(void*) * maxSize);
}

void InsertArrayRear(struct Array *arg, void *element)
{
	addArrayByIndex(arg, element, arg->count);
}

void InsertArrayHead(struct Array *arg, void *element)
{
	addArrayByIndex(arg, element, 0);
}

void *getArrayByIndex(struct Array *arg, int offset)
{
	offset = rightOffset(arg, offset);
	if(offset > arg->count-1)
	{
		fprintf(stderr, "Array: petch nothing\n");
		return NULL;
	}
	return (arg->base)[offset];
}

void *getArrayHead(struct Array *arg)
{
	return getArrayByIndex(arg, 0);
}


void *getArrayRear(struct Array *arg)
{
	return getArrayByIndex(arg, -1);
}

int getArrayLength(struct Array *arg)
{
	return arg->count;
}

int getArrayMaxSize(struct Array *arg)
{
	return arg->maxSize;
}

void addArrayByIndex(struct Array *arg, void *element, int offset)
{
	int temp;
	
	if (arg->count >= arg->maxSize)
	{
		fprintf(stderr, "array: add full array\n");
		return;
	}
	
	offset = rightOffset(arg,offset);
	if (offset > arg->count)
	{
		fprintf(stderr, "array: add out of array\n");
		return;
	}
	/* now, offset is leagal */
	
	temp = arg->count;
	while (temp > offset)
	{
		(arg->base)[temp] = (arg->base)[temp-1];
		temp -= 1;
	}
	arg->base[temp] = element;
	
	arg->count += 1;
}

void removeArrayByIndex(struct Array *arg, int offset)
{
	int temp;
	offset = rightOffset(arg,offset);
	if (offset > arg->count-1)
	{
		fprintf(stderr, "array: remove empty slot\n");
		return;
	}
	
	temp = offset;
	while (temp < arg->count-1)
	{
		(arg->base)[temp] = (arg->base)[temp+1];
		temp += 1;
	}
	arg->count -= 1;
}

void removeArrayHead(struct Array *arg)
{
	removeArrayByIndex(arg, 0);
}

void removeArrayRear(struct Array *arg)
{
	removeArrayByIndex(arg, -1);
}

void modifyArrayByIndex(struct Array *arg, void *element, int offset)
{
	offset = rightOffset(arg, offset);
	if (offset > arg->count - 1)
	{
		fprintf(stderr, "array: modify empty slot\n");
		return;
	}
	(arg->base)[offset] = element;
}

int isArrayEmpty(struct Array *arg)
{
	return !arg->count;
}