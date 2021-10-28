#include <stdlib.h>
#include <stdio.h>
#include "arraylist.h"

int main()
{
    arraylist * list = arraylist_create();

    int val = 10;
    int* number = &val;

    arraylist_add(list, number);
    arraylist_add(list, number);

    for(int i=0; i<arraylist_size(list); i++){
        printf("%d\n", (*(int*)arraylist_get(list, i)));
    }
    
    arraylist_destroy(list);

    return 0;
}