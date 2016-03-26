/*
	Xu XuTao
	create : unknown
	modify : 2016, 3, 26
	note : who wants to read this fucking code?
*/
#include "Tree.h"


int TreeMain(void)
{
    struct TreeTable tmp;
    
    int a = 100;
    int b = 4;
    int c = 5;
    int i;
    int *array[3] = {&a, &b, &c}; 
    binary_tree_init(&tmp, (void**)array, 3);
    int **ret = (int**)binary_tree_traversal(&tmp, PREORDER); 
    for(i = 1; i <= *ret[0]; i++)
    {
        printf("%d\n", *ret[i]);
    }
    return 0;
}
