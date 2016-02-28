#include <stdio.h>
#include "Queue.h"

#define PRE 0
#define IN 1
#define POST 2

struct TreeNode {
	void *value;
	struct TreeNode *left;
	struct TreeNode *right;
};



void initBinaryTree(struct TreeNode *root, void **value, int num);
void** traversalTree(struct TreeNode * root, int flag); 
