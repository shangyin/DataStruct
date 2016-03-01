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


#include <stdio.h>
#include <stdlib.h>

struct Array
{
	void **base;
	int maxSize;
	int count;
};


void initArray(struct Array *arg, int maxSize);
int isArrayEmpty(struct Array *arg);
int getArrayLength(struct Array *arg);
int getArrayMaxSize(struct Array *arg);

void addArrayByIndex(struct Array *arg, void *element, int offset);
void InsertArrayRear(struct Array *arg, void *element);
void InsertArrayHead(struct Array *arg, void *element);

void *getArrayByIndex(struct Array *arg, int offset);
void *getArrayHead(struct Array *arg);
void *getArrayRear(struct Array *arg);

void modifyArrayByIndex(struct Array *arg, void *element, int offset);

void removeArrayByIndex(struct Array *arg, int offset);
void removeArrayHead(struct Array *arg);
void removeArrayRear(struct Array *arg);