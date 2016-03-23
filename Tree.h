/*
	Xu XuTao
	create : unknown
	modify : 2016, 3, 23
*/

#include <stdio.h>
#include "Queue.h"

/*
	TREE_H should be added
*/

#define PRE 0
#define IN 1
#define POST 2

struct TreeNode {
	void *value;
	struct TreeNode *left;
	struct TreeNode *right;
};



void binary_tree_init(struct TreeNode *root, void **value, int num);
void** binary_tree_traversal(struct TreeNode * root, int flag); 
