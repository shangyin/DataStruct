#include <stdio.h>

#include "Stack.h"
#include "Queue.h"

#define PRE 0
#define IN 1
#define POST 2

struct TreeNode {
	void *value;
	struct TreeNode *left;
	struct TreeNode *right;
};

void initBinaryTree(struct TreeNode *root, void **value, int num)
{
	struct Queue tQueue;
	struct TreeNode **ret;
	int count = 0;
	int pSize = sizeof(void*);
	
	initQueue(&tQueue, num, sizeof(void*));
	inQueue(tQueue, &root);
	while (!isEmptyQueue(tQueue))
	{
		if (count >= num)
		{
			break;
		}
		ret = deQueue(tQueue);
		if (value[count])
		{
			*ret ? *ret : (*ret = (struct TreeNode*)malloc(sizeof(struct TreeNode)));
			(*ret)->value = value[count];
			(*ret)->left = (*ret)->right = NULL;
			inQueue(tQueue, &(*ret)->left);
			inQueue(tQueue, &(*ret)->right);
		}
		count++;
	}
	destroyQueue(tQueue);
	
}