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

/*
	ARRAY_H should be added.
*/


#include <stdio.h>
#include <stdlib.h>

struct Array
{
	void **base;
	int maxSize;
	int count;
};


void array_init(struct Array *arg, int maxSize);
int array_is_empty(struct Array *arg);
int array_get_length(struct Array *arg);
int array_get_maxsize(struct Array *arg);

void array_add_by_index(struct Array *arg, void *element, int offset);
void array_insert_rear(struct Array *arg, void *element);
void array_insert_head(struct Array *arg, void *element);

void *array_get_by_index(struct Array *arg, int offset);
void *array_get_head(struct Array *arg);
void *array_get_rear(struct Array *arg);

void array_set_by_index(struct Array *arg, void *element, int offset);

void array_remove_by_index(struct Array *arg, int offset);
void array_remove_head(struct Array *arg);
void array_remove_rear(struct Array *arg);