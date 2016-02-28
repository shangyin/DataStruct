#include "Tree.h"

void initBinaryTree(struct TreeNode *root, void **value, int num)
{
	struct Queue tQueue;
	struct TreeNode **ret;
	int count = 0;
	int pSize = sizeof(void*);
	
	initQueue(&tQueue, num, sizeof(void*));
	inQueue(&tQueue, &root);
	while (!isEmptyQueue(&tQueue))
	{
		if (count >= num)
		{
			break;
		}
		ret = deQueue(&tQueue);
		if (value[count])
		{
			*ret ? *ret : (*ret = (struct TreeNode*)malloc(sizeof(struct TreeNode)));
			(*ret)->value = value[count];
			(*ret)->left = (*ret)->right = NULL;
			inQueue(&tQueue, &(*ret)->left);
			inQueue(&tQueue, &(*ret)->right);
		}
		count++;
	}
	destroyQueue(&tQueue);
	
}


/* sub process for preOrderTree */
static void traversal(struct TreeNode* root, void** tmp, int* count, int flag) {
	if (!root) {
		return;
	}
	else {
		if (flag == PRE) {
			tmp[*count] = root->value;
            *count += 1;
		}
		traversal(root->left, tmp, count, flag);
		if (flag == IN) {
			tmp[*count] = root->value;
            *count += 1;
		}
		traversal(root->right, tmp, count, flag);
		if (flag == POST) {
			tmp[*count] = root->value;
            *count += 1;
		}
	}
}

/* return an array for the result ordering */
void** traversalTree(struct TreeNode * root, int flag) {
	void *tmp[4096] = { 0 };
	int count = 0;
	traversal(root, tmp, &count, flag);
	void **ret = (void**)malloc((count + 1)*sizeof(void*));
    memset(ret, 0, sizeof(void*)*(count+1));
	*(int*)(ret[0]) = count;
	memcpy(ret+1, tmp, sizeof(void*)*count);
	return ret;
}
