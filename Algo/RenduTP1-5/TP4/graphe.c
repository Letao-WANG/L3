#include "graphe.h"
#include "linkedList.h"
#include <stdio.h>

void chargeGraphe(int ***adjacence, int num_row)
{
    FILE *in = fopen("matrix.data", "r");
    int buf[1024];

    *adjacence = (int **)malloc(sizeof(int *) * num_row);
    for (int i = 0; i < num_row; i++)
    {
        (*adjacence)[i] = (int *)malloc(sizeof(int *) * num_row);
    }
    for (int i = 0; i < num_row; i++)
    {
        for (int j = 0; j < num_row; j++)
        {
            fscanf(in, "%d", &(*adjacence)[i][j]);
        }
        fscanf(in, "\n");
    }

    fclose(in);
}

int get_num_row()
{
    int num_row = 0;
    FILE *in = fopen("matrix.data", "r");
    char buf[1024];

    while (fgets(buf, sizeof(buf), in) != NULL)
    {
        num_row++;
    }
    return num_row;
}

void gh_init(grapheNode **orig_grapheNode, int data)
{
    (*orig_grapheNode) = (grapheNode *)malloc(sizeof(grapheNode));
    (*orig_grapheNode)->data = data;
    (*orig_grapheNode)->grapheNodeAdj = (grapheNode **)malloc(sizeof(grapheNode *) * 10);
    (*orig_grapheNode)->adj_num = 0;
    (*orig_grapheNode)->visited = 0;
}

void ghs_init(grapheNodes_s **grapheNodes, int data)
{
    *grapheNodes = (grapheNodes_s *)malloc(sizeof(grapheNodes_s));
    (*grapheNodes)->grapheNodes = (grapheNode **)malloc(sizeof(grapheNode *) * 10);
    grapheNode *first;
    gh_init(&first, data);
    (*grapheNodes)->grapheNodes[0] = first;
    (*grapheNodes)->nodes_num = 1;
}

void gh_insert(grapheNodes_s *grapheNodes, grapheNode **spec_grapheNode, int data)
{
    if (*spec_grapheNode != NULL)
    {
        grapheNode *add_grapheNode;
        gh_init(&add_grapheNode, data);
        (*spec_grapheNode)->grapheNodeAdj[(*spec_grapheNode)->adj_num] = add_grapheNode;
        (*spec_grapheNode)->adj_num++;
        add_grapheNode->grapheNodeAdj[add_grapheNode->adj_num] = *spec_grapheNode;
        add_grapheNode->adj_num++;
        ghs_insert(grapheNodes, add_grapheNode);
    }
}

void gh_insert_node(grapheNode **spec_grapheNode, grapheNode **add_grapheNode)
{
    if (*spec_grapheNode != NULL && *add_grapheNode != NULL)
    {
        (*spec_grapheNode)->grapheNodeAdj[(*spec_grapheNode)->adj_num] = *add_grapheNode;
        (*spec_grapheNode)->adj_num++;
        (*add_grapheNode)->grapheNodeAdj[(*add_grapheNode)->adj_num] = *spec_grapheNode;
        (*add_grapheNode)->adj_num++;
    }
}

void ghs_insert(grapheNodes_s *graphe_nodes, grapheNode *add_grapheNode)
{
    graphe_nodes->grapheNodes[graphe_nodes->nodes_num] = add_grapheNode;
    graphe_nodes->nodes_num++;
}

grapheNode **gh_voisin(grapheNodes_s *nodes, grapheNode *node, int *len)
{
    // int array_nodes[] = {1, 2, 3, 4, 5, 6, 7, 8};
    if (node == NULL)
    {
        printf("NULL?");
    }
    // printf("arbre %d", node->adj_num);
    if (node != NULL && node->grapheNodeAdj != NULL)
    {
        *len = node->adj_num;
        return node->grapheNodeAdj;
    }
    else
    {
        return NULL;
    }
}

grapheNode *searchNode(grapheNodes_s *nodes, int data)
{
    for (int i = 0; i < 9; i++)
    {
        if (nodes->grapheNodes[i]->data == data)
        {
            return nodes->grapheNodes[i];
        }
    }
    return NULL;
}
void BFS(grapheNodes_s *nodes)
{
    // EDGE
    char *title = "From Type, From Name, Edge, To Type, To Name";
    FILE *fPtr_edge;
    fPtr_edge = fopen("./output/edges.csv", "w");
    if (fPtr_edge == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fPtr_edge, "%s\n", title);

    // NODE
    char *title_node = "Type, Name, Description, Image, Reference";
    FILE *fPtr_node;
    fPtr_node = fopen("./output/nodes.csv", "w");
    if (fPtr_node == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fPtr_node, "%s\n", title_node);
    fprintf(fPtr_node, "grapheNode, %d, NULL, NULL, NULL\n", nodes->grapheNodes[2]->data);

    //3
    grapheNode *graph_node = nodes->grapheNodes[2];

    ll_s *F;
    ll_init(&F, graph_node->data);

    for (int i = 0; i < nodes->nodes_num; i++)
    {
        nodes->grapheNodes[i]->visited = 0;
    }
    graph_node->visited = 1;

    while (F != NULL)
    {
        grapheNode *u = searchNode(nodes, ll_firstNode(F)->data);
        int len = u->adj_num;
        grapheNode **voisins = u->grapheNodeAdj;
        for (int i = 0; i < len; i++)
        {
            // printf("node : %d, node voisin %d, visited %d\n", u->data, voisins[i]->data, voisins[i]->visited);
            if (voisins[i]->visited == 0)
            {
                voisins[i]->visited = 1;
                // printf("visited %d\n", u->grapheNodeAdj[i]->visited);
                F = ll_lastNode(F);
                ll_insert(&F, voisins[i]->data);
                // printf("F :%d, F->next :%d\n", F->data, F->next->data);
                // F = F->next;
                // printf("F :%d\n", F->data);
                fprintf(fPtr_edge, "Node, %d, NEXT, Node, %d\n", u->data, voisins[i]->data);
                fprintf(fPtr_node, "grapheNode, %d, NULL, NULL, NULL\n", voisins[i]->data);
            }
            ll_view(ll_firstNode(F));
        }
        // printf("delete %d\n", ll_firstNode(F)->data);
        // printf("F :%d\n", F->data);
        ll_deleteFirst(&F);
    }
    fclose(fPtr_edge);
    fclose(fPtr_node);
}

// Procédure qui marque tous les sommets par ordre de voisinage depuis un sommet de
// référence
// Paramètres :
// adjacence : matrice d’adjacence du graphe
// ordre : nombre de sommets
// s : numéro du sommet de référence

void marquerVoisins(int **adjacence, int ordre, int s)
{
    int *marques;
    int x, y;

    marques = (int *)malloc(sizeof(int) * ordre);

    for (x = 0; x < ordre; x++)
    {
        marques[x] = 0;
    }

    marques[s] = 1;

    for (x = 0; x < ordre; x++)
    {
        if (marques[x])
        {
            for (y = 0; y < ordre; y++)
            {
                if (adjacence[x][y] && !marques[y])
                {
                    marques[y] = 1;
                }
            }
        }
        for (int i = 0; i < ordre; i++)
        {
            printf("%d ", marques[i]);
        }
        printf("\n");
    }
}

#define INFINI 1000.0 // un poids réel supérieur à la plus grande longueur totale
// Fonction qui retourne l’arbre couvrant de poids minimum d’un graphe valué et non orienté
// depuis un sommet de référence aléatoire
// Paramètres :
// adjacencePoids : matrice d’adjacence pondérée du graphe
// ordre : nombre de sommets
void *prim(int **adjacencePoids, int ordre)
{
    int s = 3;
    // EDGE
        char *title = "From Type, From Name, Edge, To Type, To Name";
        FILE *fPtr_edge;
        fPtr_edge = fopen("./output/edges.csv", "w");
        if (fPtr_edge == NULL)
        {
            printf("Unable to create file.\n");
            exit(EXIT_FAILURE);
        }
        fprintf(fPtr_edge, "%s\n", title);

        // NODE
        char *title_node = "Type, Name, Description, Image, Reference";
        FILE *fPtr_node;
        fPtr_node = fopen("./output/nodes.csv", "w");
        if (fPtr_node == NULL)
        {
            printf("Unable to create file.\n");
            exit(EXIT_FAILURE);
        }
        fprintf(fPtr_node, "%s\n", title_node);
        fprintf(fPtr_node, "grapheNode, %d, NULL, NULL, NULL\n",s);

    // Variables locales
    arbreNode *arbre; // arbre d’incidence nœud-arc de poids minimum à retourner
    ar_init(&arbre, s);
    int indiceA = 0;   // indice de l’arbre initialisé à 0
    int *marques;      // tableau dynamique indiquant si les sommets sont marqués ou non
    int x, y, ymin; // numéros de sommets intermédiaires
    float min;         // distance minimale du prochain sommet à marquer
    // Allouer l’arbre de « ordre-1 » arêtes et le tableau marque de « ordre » entiers
    marques = (int *)malloc(sizeof(int) * ordre);

    // Initialiser le marquage des sommets à 0
    for (x = 0; x < ordre; x++)
    {
        marques[x] = 0;
    }
    // Choisir un sommet s aléatoirement compris entre 0 et ordre-1
    // s = rand() % ordre;
    // Marquer le sommet aléatoire s
    marques[s-1] = 1;
    //tant que les arêtes de l’arbre ne sont pas toutes traitées
    while (indiceA < ordre - 1)
    {
        // Initialiser la longueur minimale à l’INFINI
        min = INFINI;
        // Pour tous les sommets x marqués
        // Chercher le sommet de longueur minimale « ymin » adjacent à x
        // et non marqué
        int xmin;
        for (x = 0; x < ordre; x++)
        {
            if (marques[x])
            {
                for (y = 0; y < ordre; y++)
                {
                    if (adjacencePoids[x][y] && !marques[y] &&
                        adjacencePoids[x][y] < min)
                    {
                        min = adjacencePoids[x][y]; // poids min
                        ymin = y;                   // sommet y de poids min
                        xmin = x;
                    }
                }
            }
        }
        // marquer le sommet « ymin » de longueur minimale
        marques[ymin] = 1;
        // Insérer l’arête (x, ymin) de longueur min à la position « indiceA » de l’arbre
        printf("%d -> %d \n", xmin + 1, ymin + 1);
        // Passer à l’arête suivante de l‘arbre
        indiceA++;

        // Output csv files
        fprintf(fPtr_edge, "Node, %d, NEXT, Node, %d\n", xmin + 1, ymin + 1);
        fprintf(fPtr_node, "grapheNode, %d, NULL, NULL, NULL\n", ymin + 1);
    }
}