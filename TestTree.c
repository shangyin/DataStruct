#include "Tree.h"


int TreeMain(void)
{
    struct TreeNode tmp;
    
    int a = 100;
    int b = 4;
    int c = 5;
    int i;
    int *array[3] = {&a, &b, &c}; 
    initBinaryTree(&tmp, (void**)array, 3);
    int **ret = (int**)traversalTree(&tmp, PRE); 
    for(i = 1; i <= ret[0]; i++)
    {
        printf("%d\n", *(ret[i]));
    }
    return 0;
}
