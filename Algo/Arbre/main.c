#include <stdlib.h>
#include <stdio.h>

#include "arbre.h"

int main()
{
    arbreNode *root;
    init(&root, 3);
    insert(&root, 2);
    insert(&root, 4);

    // insert(&(root->child[0]), 5);
    // insert(&(root->child[0]), 6);
    // insert(&(root->child[1]), 7);
    arbreNode *dest = root;
    searchArbreNode(root, dest, 4);
    insert(&dest, 5);
    // // printf("dest %d\n", dest->data);
    insert(&dest, 6);
    // printf("node data %d\n", dest->data);
    // printf("root data %d\n", root->data);
    // printf("root parent data %d\n", root->parent->data);
    // printf("arbre %d\n", searchArbreNode(root, 2)->data);
    // ar_firstNode(root);
    view(root);
    // view(dest);

    // create_edges_file(root);
    // create_arbreNodes_file(root);

    return 0;
}