#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    int val;
    int height;
    struct node *childLeft, *childRight;
} node, *ptrNode;

ptrNode newNode(int);

ptrNode constructor(ptrNode, int, ptrNode);

void parcoursPrefixe(ptrNode );
void parcoursInfixe(ptrNode );
void parcoursPostfixe(ptrNode );

ptrNode rechercheNode(ptrNode, int);
// n : the node to be inserted
void insertNode(ptrNode, ptrNode, int);
