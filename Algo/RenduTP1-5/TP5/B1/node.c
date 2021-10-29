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
        newNode->childLeft = NULL;
        newNode->childRight = NULL;
    }
    else
    {
        printf("There are some problems for allocation memory\n");
    }
    return newNode;
}

void printTree(ptrNode n, int position, int gap)
{
    if(n){
        gap = gap-2;
        printfNodes(n->childLeft, n->childRight, position, gap);
        printTree(n->childLeft, position-gap, gap);
        printTree(n->childRight, position+gap, gap);
    }
}
void printfNodes(ptrNode left, ptrNode right, int position, int gap)
{
    for(int i=gap; i>0; i--){
        printfSpace(position-gap+i);
        if(left){
            printf("/");
        }
        printfSpace(2*(gap-i));
        if(right){
            printf("\\");
        }
        printf("\n");
    }

    printfSpace(position-gap);
    if(left){
        printf("%d", left->val);
    }
    printfSpace(2*gap);
    if(right){
        printf("%d", right->val );
    }
    printf("\n");
}

void printfSpace(int position){
    for(int i=0; i<position; i++)
    {
        printf(" ");
    }
}

arraylist *constructTrees(int start, int end)
{
    arraylist *list = arraylist_create();

    if (start > end)
    {
        arraylist_add(list, NULL);
        return list;
    }

    for (int i = start; i <= end; i++)
    {
        arraylist *leftSubtree = constructTrees(start, i - 1);
        arraylist *rightSubtree = constructTrees(i + 1, end);

        for (int j = 0; j < arraylist_size(leftSubtree); j++)
        {
            ptrNode left = arraylist_get(leftSubtree, j);
            for (int k = 0; k < arraylist_size(rightSubtree); k++)
            {
                ptrNode right = arraylist_get(rightSubtree, k);
                ptrNode node = newNode(i);
                node->childLeft = left;
                node->childRight = right;
                arraylist_add(list, node);
            }
        }
    }
    return list;
}