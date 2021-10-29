#include <stdlib.h>
#include <stdio.h>
#include "node.h"


int main()
{
    arraylist* trees = constructTrees(1, 4);

    int position = 20;
    int gap = 7;
    for (int i = 0; i < arraylist_size(trees); i++)
    {
        printf("\n*************************************************\n");
        ptrNode root = (ptrNode)arraylist_get(trees, i);

        printfSpace(position);
        printf("%d\n", root->val);
        printTree(root, position, gap);
    }

    return 0;
}