#include "Tree.h"


int main(void)
{
    struct TreeNode tmp;
    
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int i;
    int *array[4] = {&a, &b, &c, &d}; 
    initBinaryTree(&tmp, (void**)array, 4);
    int **ret = (int**)traversalTree(&tmp, PRE); 
    for(i = 0; i < 4; i++)
    {
        printf("%d\n", *(ret[i]));
    }
    return 0;
}
