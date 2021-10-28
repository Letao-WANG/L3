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

// void parcoursPrefixe(ptrNode n)
// {
//     if (n)
//     {
//         printf("%d ", n->val);
//         parcoursPrefixe(n->childLeft);
//         parcoursPrefixe(n->childRight);
//     }
// }

void parcoursPrefixe(ptrNode n)
{
    if (n)
    {
        printf("%d ", n);
        parcoursPrefixe(n->childLeft);
        parcoursPrefixe(n->childRight);
    }
}

arraylist* constructTrees(int start, int end)
{
    arraylist * list = arraylist_create();
 
    if (start > end)
    {
        arraylist_add(list, NULL);
        return list;
    }
 
    /*  iterating through all values from start to end  for constructing\
        left and right subtree recursively  */
    for (int i = start; i <= end; i++)
    {
        /*  constructing left subtree   */
        arraylist* leftSubtree  = constructTrees(start, i - 1);
 
        /*  constructing right subtree  */
        arraylist* rightSubtree = constructTrees(i + 1, end);
 
        /*  now looping through all left and right subtrees and connecting
            them to ith root  below  */
        for (int j = 0; j < arraylist_size(leftSubtree); j++)
        {
            ptrNode left = arraylist_get(leftSubtree, j);
            for (int k = 0; k < arraylist_size(rightSubtree); k++)
            {
                ptrNode right = arraylist_get(rightSubtree, k);
                ptrNode node = newNode(i);// making value i as root
                node->childLeft = left;              // connect left subtree
                node->childRight = right;            // connect right subtree
                arraylist_add(list, node);           // add this tree to list
            }
        }
    }
    return list;
}