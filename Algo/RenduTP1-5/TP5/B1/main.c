#include <stdlib.h>
#include <stdio.h>
#include "node.h"


int main()
{
    arraylist* trees = constructTrees(1, 3);

    printf("size : %d\n", arraylist_size(trees));

    // for (int i = 0; i < arraylist_size(trees); i++)
    // {
    //     parcoursPrefixe( (*(ptrNode*)arraylist_get(trees, i)));
    // }

    // printf("%d\n", (*(ptrNode*)arraylist_get(trees, 0))->val);

    // arraylist * trees = arraylist_create();

    // ptrNode node = newNode(124);
    // arraylist_add(trees, node);
    ptrNode p1 = (*(ptrNode*)arraylist_get(trees, 0));
    printf("%d\n", p1);
    printf("val : %d\n", p1->val);
    printf("left : %d\n", p1->childLeft);
    printf("right : %d\n", p1->childRight);
    // printf("%d\n", (*(ptrNode*)arraylist_get(trees, 1)));
    // printf("%d\n", (*(ptrNode*)arraylist_get(trees, 2)));
    // printf("%d\n", (*(ptrNode*)arraylist_get(trees, 3)));
    // printf("%d\n", (*(ptrNode*)arraylist_get(trees, 4)));

    return 0;
}