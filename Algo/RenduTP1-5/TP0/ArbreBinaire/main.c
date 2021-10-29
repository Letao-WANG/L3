#include <stdlib.h>
#include <stdio.h>
#include "node.h"


int main()
{
    ptrNode n = constructor(constructor(newNode(5), 1, NULL), 3, constructor(newNode(2), 4, newNode(0)));
    
    parcoursPrefixe(n);
    printf("\n");
    parcoursInfixe(n);
    printf("\n");
    parcoursPostfixe(n);
    printf("\n");

    return 0;
}