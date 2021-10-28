#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    int height;
    struct node *childLeft, *childRight;
} node, *ptrNode;

ptrNode newNode(int);


void parcoursPrefixe(ptrNode );
void parcoursInfixe(ptrNode );
void parcoursPostfixe(ptrNode );

ptrNode rechercheNode(ptrNode, int);
// n : the node to be inserted
ptrNode insertAVL(ptrNode, int);

int max(int, int);
 
int height(ptrNode);
 
ptrNode rightRotate(ptrNode);
 
ptrNode leftRotate(ptrNode);
int getBalance(ptrNode);