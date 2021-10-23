#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

typedef struct grapheNode
{
    int data;
    struct grapheNode **grapheNodeAdj;
    int adj_num;
    int visited;
} grapheNode;

typedef struct grapheNodes
{
    struct grapheNode **grapheNodes;
    int nodes_num;
} grapheNodes_s;

void chargeGraphe(int***, int);
int get_num_row();
void gh_init(grapheNode **, int);
void ghs_init(grapheNodes_s **, int);

void gh_insert(grapheNodes_s *, grapheNode **, int);
void gh_insert_node(grapheNode **, grapheNode **);
void ghs_insert(grapheNodes_s *, grapheNode *);
grapheNode **gh_voisin(grapheNodes_s *, grapheNode *, int *);

grapheNode *searchNode(grapheNodes_s *, int);

void BFS(grapheNodes_s *);
void DFS(grapheNodes_s *);

void marquerVoisins(int**, int, int);
void plusCourtChemin(int **, int, int, int *, int *);