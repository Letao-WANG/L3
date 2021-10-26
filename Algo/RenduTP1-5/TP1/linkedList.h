#include <stdio.h>
#include <stdlib.h>

typedef struct ll_s
{
    int data;
    struct ll_s* prev;
    struct ll_s* next;
} ll_s;

void ll_init(ll_s**, int);

void ll_insert(ll_s** , int);

void ll_delete(ll_s**);
void ll_deleteFirst(ll_s **);
void ll_deleteLast(ll_s **);
ll_s * ll_lastNode(ll_s*);
ll_s * ll_firstNode(ll_s*);
void ll_view(ll_s*);