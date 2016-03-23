/*
	Xu XuTao
	create : 2016, 3, 1
	modify : 2016, 3, 23
	note : well checked
*/

/*
	the length of array is set when its init.
	the variable length version may be built in the future.
*/
#include "Array.h"

/* 
	to make negative index works.
	when index is -1 and there has NO element, -1 should means 0.  
*/
#define rightOffset(a,index) (index < 0 ? (((a->count+index)<0)?0:(a->count+index)) : index)


void array_init(struct Array *arg, int maxSize)
{
	arg->count = 0;
	arg->maxSize = maxSize;
	arg->base = malloc(sizeof(void*) * maxSize);
	if (!arg->base)
	{
		fprintf(stderr, "malloc returns NULL\n");
	}
}

void array_insert_rear(struct Array *arg, void *element)
{
	array_add_by_index(arg, element, arg->count);
}

void array_insert_head(struct Array *arg, void *element)
{
	array_add_by_index(arg, element, 0);
}

void *array_get_by_index(struct Array *arg, int offset)
{
	offset = rightOffset(arg, offset);
	if(offset > arg->count-1)
	{
		fprintf(stderr, "Array: petch nothing\n");
		return NULL;
	}
	return (arg->base)[offset];
}

void *array_get_head(struct Array *arg)
{
	return array_get_by_index(arg, 0);
}


void *array_get_rear(struct Array *arg)
{
	return array_get_by_index(arg, -1);
}

int array_get_length(struct Array *arg)
{
	return arg->count;
}

int array_get_maxsize(struct Array *arg)
{
	return arg->maxSize;
}

void array_add_by_index(struct Array *arg, void *element, int offset)
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

void array_remove_by_index(struct Array *arg, int offset)
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

void array_remove_head(struct Array *arg)
{
	array_remove_by_index(arg, 0);
}

void array_remove_rear(struct Array *arg)
{
	array_remove_by_index(arg, -1);
}

void array_set_by_index(struct Array *arg, void *element, int offset)
{
	offset = rightOffset(arg, offset);
	if (offset > arg->count - 1)
	{
		fprintf(stderr, "array: modify empty slot\n");
		return;
	}
	(arg->base)[offset] = element;
}

int array_is_empty(struct Array *arg)
{
	return !arg->count;
}