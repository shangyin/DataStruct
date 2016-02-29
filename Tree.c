#include "Tree.h"

void initBinaryTree(struct TreeNode *root, void **value, int num)
{
	struct Queue tQueue;
	struct TreeNode **ret;
	int count = 0;
	
	initQueue(&tQueue, num);
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
			tmp[(*count)++] = root->value;
		}
		traversal(root->left, tmp, count, flag);
		if (flag == IN) {
			tmp[(*count)++] = root->value;
		}
		traversal(root->right, tmp, count, flag);
		if (flag == POST) {
			tmp[(*count)++] = root->value;
		}
	}
}

/* return an array for the result */
void** traversalTree(struct TreeNode * root, int flag) {
	void *tmp[4096] = { 0 };
	int count = 0;
	void **ret;

	traversal(root, tmp, &count, flag);
	ret = (void**)malloc((count + 1)*sizeof(void*));
	ret[0] = count;			/* NOTE: works in IA-32 */
	memcpy(ret+1, tmp, sizeof(void*)*count);
	return ret;
}
