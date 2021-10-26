#include <stdlib.h>
#include <stdio.h>
#include "graphe.h"

int main()
{
    grapheNodes_s *grapheNodes;
    ghs_init(&grapheNodes, 1);

    //1
    gh_insert(grapheNodes, &(grapheNodes->grapheNodes[0]), 2);
    gh_insert(grapheNodes, &(grapheNodes->grapheNodes[0]), 3);

    //2
    gh_insert(grapheNodes, &(grapheNodes->grapheNodes[1]), 4);
    gh_insert(grapheNodes, &(grapheNodes->grapheNodes[1]), 5);

    //3
    //3 -> 2
    gh_insert_node(grapheNodes, &(grapheNodes->grapheNodes[2]), &(grapheNodes->grapheNodes[1]));
    gh_insert(grapheNodes, &(grapheNodes->grapheNodes[2]), 6);

    //4
    gh_insert(grapheNodes, &(grapheNodes->grapheNodes[3]), 7);
    gh_insert(grapheNodes, &(grapheNodes->grapheNodes[3]), 8);

    //7-> 5
    gh_insert_node(grapheNodes, &(grapheNodes->grapheNodes[6]), &(grapheNodes->grapheNodes[4]));

    //8 -> 6
    gh_insert_node(grapheNodes, &(grapheNodes->grapheNodes[7]), &(grapheNodes->grapheNodes[5]));

    //8 -> 7
    gh_insert_node(grapheNodes, &(grapheNodes->grapheNodes[7]), &(grapheNodes->grapheNodes[6]));

    /////////////////////
    // //2
    // gh_insert(grapheNodes, &(root->grapheNodeAdj[0]), 3);
    // gh_insert(grapheNodes, &(root->grapheNodeAdj[0]), 4);
    // gh_insert(grapheNodes, &(root->grapheNodeAdj[0]), 5);

    // //3
    // gh_insert(grapheNodes, &(root->grapheNodeAdj[1]), 6);

    // //4
    // gh_insert(grapheNodes, &(root->grapheNodeAdj[0]->grapheNodeAdj[2]), 7);
    // gh_insert(grapheNodes, &(root->grapheNodeAdj[0]->grapheNodeAdj[2]), 8);

    // grapheNodes->grapheNodes[0]->data = 10;
    // printf("%d\n", root->data);
    // printf("%d\n", root->grapheNodeAdj[0]->data);
    // for (int i = 0; i < 9; i++)
    // {
    //     printf("num : %d -> %d\n", i, grapheNodes->grapheNodes[i]->data);
    // }

    BFS(grapheNodes);

    // view(root);
    // printf("%d\n", grapheNodes->grapheNodes[4]->grapheNodeAdj[2]->data);
    // printf("%d\n", grapheNodes->grapheNodes[0]->data);
    return 0;
}