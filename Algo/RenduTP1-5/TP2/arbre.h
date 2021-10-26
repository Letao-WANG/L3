#include <stdio.h>
#include <stdlib.h>

typedef struct arbreNode
{
    int data;
    struct arbreNode *parent;
    struct arbreNode **child;
    int child_num;
    int visited;
} arbreNode;

void ar_init(arbreNode **, int);

void ar_insert(arbreNode **, int);

void searchArbreNode(arbreNode*, arbreNode*, int);

void delete_arbreNode(arbreNode **);

void ar_view(arbreNode *);

void create_edges_file(arbreNode *);

void write_edges_file(arbreNode *);

void create_arbreNodes_file(arbreNode *);

void write_arbreNodes_file(arbreNode *);

int appear(int[], int);
