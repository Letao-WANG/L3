#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

int main()
{
    ll_s *F;
    ll_init(&F, 1);
    // ll_insert(&root, 2);
    // root = root->next;
    // ll_insert(&root, 3);
    // root = root->next;
    // delete(&root);
    // ll_s * *node = ll_firstNode(root->next);
    while (F != NULL)
    {
        ll_deleteFirst(&F);
        ll_view(ll_firstNode(F));
    }
    // ll_s * lastone = lastNode(root);
    // delete(&lastone);
    // delete(&(root->next));
    // printf("%p\n", root->next);
    // printf("%p\n", root);

    return 0;
}