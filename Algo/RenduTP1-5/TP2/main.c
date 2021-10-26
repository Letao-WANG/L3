#include <stdlib.h>
#include <stdio.h>
#include "graphe.h"

int main()
{
    int **matrixAdjacency;
    int num_row = get_num_row(matrixAdjacency);
    chargeGraphe(&matrixAdjacency, num_row);

    int *l = (int*)malloc(sizeof(int)*num_row);
    int *pred = (int*)malloc(sizeof(int)*num_row);
    plusCourtChemin(matrixAdjacency, num_row, 2, l, pred);

    for(int i =0; i<num_row; i++)
    {
        printf("%d ", l[i]);
    }
    printf("\n");

    return 0;
}