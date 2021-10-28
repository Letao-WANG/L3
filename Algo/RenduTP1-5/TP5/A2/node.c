#include <stdio.h>
#include <stdlib.h>
#include "node.h"

ptrNode newNode(int value)
{
    ptrNode newNode;

    newNode = (ptrNode)malloc(sizeof(node));
    if (newNode)
    {
        newNode->val = value;
        newNode->height = 1; 
        newNode->childLeft = NULL;
        newNode->childRight = NULL;
    }
    else
    {
        printf("There are some problems for allocation memory\n");
    }
    return newNode;
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


int height(ptrNode n)
{
    if (n == NULL)
        return 0;
    return n->height;
}
 
int max(int a, int b)
{
    return (a > b)? a : b;
}

ptrNode rightRotate(ptrNode y)
{
    ptrNode x = y->childLeft;
    ptrNode z = x->childRight;
 
    x->childRight = y;
    y->childLeft = z;
    y->height = max(height(y->childLeft), height(y->childRight))+1;
    x->height = max(height(x->childLeft), height(x->childRight))+1;
 
    return x;
}
 
ptrNode leftRotate(ptrNode x)
{
    ptrNode y = x->childRight;
    ptrNode z = y->childLeft;
 
    y->childLeft = x;
    x->childRight = z;
    x->height = max(height(x->childLeft), height(x->childRight))+1;
    y->height = max(height(y->childLeft), height(y->childRight))+1;
 
    return y;
}
 
int getBalance(ptrNode n)
{
    if (n == NULL)
        return 0;
    return height(n->childLeft) - height(n->childRight);
}

ptrNode insertAVL(ptrNode node, int val){
if (node == NULL)
        return(newNode(val));
 
    if (val < node->val)
        node->childLeft  = insertAVL(node->childLeft, val);
    else if (val > node->val)
        node->childRight = insertAVL(node->childRight, val);
    else 
        return node;
 
    node->height = 1 + max(height(node->childLeft),
                           height(node->childRight));
 
    int balance = getBalance(node);
 
    // Left Left Case
    if (balance > 1 && val < node->childLeft->val)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && val > node->childRight->val)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && val > node->childLeft->val)
    {
        node->childLeft =  leftRotate(node->childLeft);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && val < node->childRight->val)
    {
        node->childRight = rightRotate(node->childRight);
        return leftRotate(node);
    }
 
    return node;
}
