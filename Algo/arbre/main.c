#include <stdlib.h>
#include <stdio.h>

#include "arbre.h"

int main()
{
    nodeList list;
    initArray(&list, 5);
    for(int i=0; i<5; i++){
        node *new_node;
        initNode(new_node, i);
        insertArray(&list, i);
    }

    view(&list);

    printf("\n");

    return 0;
}