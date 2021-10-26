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

void init(arbreNode **, int);

void insert(arbreNode **, int);

void ar_firstNode(arbreNode *);

void delete_arbreNode(arbreNode **);

void view(arbreNode *);

void searchArbreNode(arbreNode *, arbreNode *, int);

void create_edges_file(arbreNode *);

void write_edges_file(arbreNode *);

void create_arbreNodes_file(arbreNode *);

void write_arbreNodes_file(arbreNode *);

int appear(int[], int);
