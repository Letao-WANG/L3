#include <stdlib.h>
#include <stdio.h>
#include "node.h"


int main()
{
    ptrNode root = NULL;

    for(int i=0; i<10;i++){
      root = insertAVL(root, i);
    }

    // Time complexity insertAVL is O(Log n), n is the number of node

    parcoursPrefixe(root);

    return 0;
}