#include<stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct nodeList * children;
} node;

typedef struct tree{
    struct node* root;
} tree;

typedef struct nodeList{
  node *nodes;
  size_t used;
  size_t size;
} nodeList;

void initNode(node*, int);
void addNode(node*, int);
void view(nodeList*);


void initArray(nodeList *, size_t);

void insertArray(nodeList *, int);

void freeArray(nodeList *);