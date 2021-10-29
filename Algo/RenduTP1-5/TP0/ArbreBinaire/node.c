#include <stdio.h>
#include <stdlib.h>
#include "node.h"

ptrNode newNode(int value)
{
    ptrNode newNode;
    static int numero;

    newNode = (ptrNode)malloc(sizeof(node));
    if (newNode)
    {
        newNode->num = numero++;
        newNode->val = value;
        newNode->childLeft = NULL;
        newNode->childRight = NULL;
    }
    else
    {
        printf("There are some problems for allocation memory\n");
    }
    return newNode;
}

ptrNode constructor(ptrNode left, int val, ptrNode right)
{
    ptrNode n = newNode(val);
    n->childLeft = left;
    n->childRight = right;

    return n;
}

void parcoursPrefixe(ptrNode n)
{
    if (n)
    {
        printf("%d ", n->val);
        parcoursPrefixe(n->childLeft);
        parcoursPrefixe(n->childRight);
    }
}

void parcoursInfixe(ptrNode n)
{
    if (n)
    {
        parcoursInfixe(n->childLeft);
        printf("%d ", n->val);
        parcoursInfixe(n->childRight);
    }
}
void parcoursPostfixe(ptrNode n)
{
if (n)
    {
        parcoursPostfixe(n->childLeft);
        parcoursPostfixe(n->childRight);
        printf("%d ", n->val);
    }
}

ptrNode rechercheNode(ptrNode n, int numNode)
{
    ptrNode tmpNode;

    if (n == NULL)
    {
        return NULL;
    }
    if (n->num == numNode)
    {
        return n;
    }
    tmpNode = rechercheNode(n->childLeft, numNode);
    if (tmpNode != NULL)
    {
        return tmpNode;
    }
    return rechercheNode(n->childRight, numNode);
}

// n : the node to be inserted
void insertNode(ptrNode n, ptrNode arbre, int numNode){
    ptrNode nodeCour = NULL;

    nodeCour = rechercheNode(arbre, numNode);
    if(nodeCour){
        n->childLeft = nodeCour->childLeft;
        nodeCour->childLeft = n;
    } else {
        printf("The node n %d does not exist \n", n->num);
    }
}
