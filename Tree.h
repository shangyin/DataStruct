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

#define PREORDER 0
#define INORDER 1
#define POSTORDER 2

struct TreeNode {
	void *value;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeTable {
	struct TreeNode *root;
	int count;
};


/* fine, this process is useless, because you can't operate with the nodes */
void binary_tree_init(struct TreeTable *table, void **value, int num);

void binary_tree_destroy(struct TreeTable * table);

/* return an array for the result */
/* ret and ret[0] should be free */
void** binary_tree_traversal(struct TreeTable * table, int flag); 

void BST_init(struct TreeTable * table);