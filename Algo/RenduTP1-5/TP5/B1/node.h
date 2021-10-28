#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

typedef struct node
{
    int val;
    struct node *childLeft, *childRight;
} node, *ptrNode;

ptrNode newNode(int);
void parcoursPrefixe(ptrNode );
arraylist* constructTrees(int, int);