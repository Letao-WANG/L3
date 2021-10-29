#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

typedef struct node
{
    int val;
    struct node *childLeft, *childRight;
} node, *ptrNode;

ptrNode newNode(int);
void printTree(ptrNode, int, int);
void printfNodes(ptrNode, ptrNode, int, int);
void printfSpace(int);
arraylist* constructTrees(int, int);