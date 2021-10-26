#include <stdlib.h>
#include <stdio.h>
#include "graphe.h"

int main()
{
    int **matrixAdjacency;
    int num_row = get_num_row(matrixAdjacency);
    chargeGraphe(&matrixAdjacency, num_row);

    // init graphe_nodes
    grapheNodes_s *graphe_nodes;
    ghs_init(&graphe_nodes, 1);

    for (int i = 1; i < num_row; i++)
    {
        grapheNode *new_grapheNode;
        gh_init(&new_grapheNode, i + 1);
        graphe_nodes->grapheNodes[graphe_nodes->nodes_num] = new_grapheNode;
        graphe_nodes->nodes_num++;

        for (int j = 0; j < i; j++)
        {
            if (matrixAdjacency[i][j] == 1)
            {
                grapheNode *node1 = searchNode(graphe_nodes, j + 1);
                grapheNode *node2 = searchNode(graphe_nodes, i + 1);
                gh_insert_node(&node1, &node2);
            }
        }
    } 
    prim(matrixAdjacency, num_row);
    return 0;
}