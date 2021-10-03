#include "arbre.h"

#include<stdio.h>

void initNode(node * nodeOrigin, int data){
    nodeOrigin = (node*)malloc(sizeof(node));
    nodeOrigin->data = data;
    nodeOrigin->prev = NULL;
    nodeOrigin->children = NULL;
}

void addNode(node *parentNode, int data){
    if(parentNode != NULL){
        node childNode;
        initNode(&childNode, data);
        insertArray(parentNode, data);
    }
}

void view(nodeList * root){
    for(int i = 0; i<root->used; i++){
        printf("%d\n", root->nodes[i]);
    }
}

void initArray(nodeList *a, size_t initialSize) {
  a->nodes = malloc(initialSize * sizeof(node));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(nodeList *a, int data) {
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size 
  if (a->used == a->size) {
    a->size *= 2;
    a->nodes = realloc(a->nodes, a->size * sizeof(int));
  }
  node *new_node;
  initNode(new_node, data);
  a->nodes[a->used++] = *new_node;
}

void freeArray(nodeList *a) {
  free(a->nodes);
  a->nodes = NULL;
  a->used = a->size = 0;
}