/*
	Xu XuTao
	create : unknown
	modify : 2016, 3, 26
	note : well checked. Hard code, should be checked again
*/
#include "Tree.h"

void binary_tree_init(struct TreeNode *root, void **value, int num)
{
	struct Queue tQueue;
	struct TreeNode **ret;
	int count = 0;
	
	queue_init(&tQueue, num);
	queue_in(&tQueue, &root);
	while (!queue_is_empty(&tQueue))
	{
		if (count >= num)
		{
			break;
		}
		ret = queue_out(&tQueue);
		if (value[count])
		{
			*ret ? *ret : (*ret = (struct TreeNode*)malloc(sizeof(struct TreeNode)));
			(*ret)->value = value[count];
			(*ret)->left = (*ret)->right = NULL;
			queue_in(&tQueue, &(*ret)->left);
			queue_in(&tQueue, &(*ret)->right);
		}
		count++;
	}
	queue_destory(&tQueue);
	
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
/* ret and ret[0] should be free */
void** binary_tree_traversal(struct TreeNode * root, int flag) {
	void *tmp[4096] = { 0 };
	int count = 0;
	void **ret;

	traversal(root, tmp, &count, flag);
	ret = (void**)malloc((count + 1)*sizeof(void*));
	ret[0] = (int*)malloc(sizeof(int));
	*(int*)ret[0] = count;
	memcpy(ret+1, tmp, sizeof(void*)*count);
	return ret;
}
