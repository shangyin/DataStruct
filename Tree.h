/*
	Xu XuTao
	create : unknown
	modify : 2016, 3, 26
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

/* return an array for the result */
/* ret and ret[0] should be free */
void** binary_tree_traversal(struct TreeNode * root, int flag); 
