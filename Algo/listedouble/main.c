#include <stdlib.h>
#include <stdio.h>

#include "listedouble.h"

int main()
{
    // init
    int array[] = {10,11,12};
    dll_s *dll1 = (dll_s*)malloc(sizeof(dll_s));
    dll_s *dll2 = (dll_s*)malloc(sizeof(dll_s));
    dll1->data = &(array[0]);
    dll1->prev = NULL;
    dll1->next = dll2;

    dll2->data = &(array[1]);
    dll2->prev = dll1;
    dll2->next = NULL;

    view(dll1);

    printf("\n");

    dll_insert(&dll2, &(array[2]));

    view(dll1);

    return 0;
}