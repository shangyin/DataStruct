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


/* sub process for preOrderTree */
void traversal(struct TreeNode* root, int* tmp, int* count, int flag) {
	if (!root) {
		return;
	}
	else {
		if (flag == PRE) {
			tmp[(*count)++] = root->val;
		}
		preOrder(root->left, tmp, count, flag);
		if (flag == IN) {
			tmp[(*count)++] = root->val;
		}
		preOrder(root->right, tmp, count, flag);
		if (flag == POST) {
			tmp[(*count)++] = root->val;
		}
	}
}

/* return an array for the result ordering */
int* traversalTree(struct TreeNode * root, int flag) {
	int tmp[4096] = { 0 };
	int count = 0;
	traversal(root, tmp, &count, flag);
	int* ret = (int*)malloc((count + 1)*sizeof(int));
	ret[0] = count;
	memcpy(ret + 1, tmp, sizeof(int)*count);
	return ret;
}
