#include "arbre.h"
#include <stdio.h>

void ar_init(arbreNode **orig_arbreNode, int data)
{
    (*orig_arbreNode) = (arbreNode *)malloc(sizeof(arbreNode));
    (*orig_arbreNode)->data = data;
    (*orig_arbreNode)->parent = NULL;
    (*orig_arbreNode)->child = (arbreNode **)malloc(sizeof(arbreNode *) * 10);
    (*orig_arbreNode)->child_num = 0;
    (*orig_arbreNode)->visited = 0;
}

void ar_insert(arbreNode **spec_arbreNode, int data)
{
    if (*spec_arbreNode != NULL)
    {
        arbreNode *add_arbreNode;
        ar_init(&add_arbreNode, data);
        (*spec_arbreNode)->child[(*spec_arbreNode)->child_num] = add_arbreNode;
        (*spec_arbreNode)->child_num++;
        add_arbreNode->parent = (*spec_arbreNode);
    }
}


void searchArbreNode(arbreNode* root, arbreNode* dest, int data)
{
    if(root->data == data){
        *dest = *root;
    }
    else if (root != NULL)
    {
        for (int i = 0; i < root->child_num; i++)
        {
            // printf("data %d -> %d\n", root->data, root->child[i]->data);
            searchArbreNode(root->child[i], dest, data);
        }
    }
}


void delete_arbreNode(arbreNode **del_arbreNode)
{
    if (*del_arbreNode != NULL)
    {
        arbreNode *parent_arbreNode = (*del_arbreNode)->parent;
        if (*((*del_arbreNode)->child) != NULL)
        {
            arbreNode **child_arbreNode = (*del_arbreNode)->child;
        }
    }
}



void ar_view(arbreNode *root)
{
    if ((*root->child) != NULL)
    {
        for (int i = 0; i < root->child_num; i++)
        {
            printf("%d -> %d\n", root->data, root->child[i]->data);
            ar_view(root->child[i]);
        }
    }
}

void create_edges_file(arbreNode *root)
{
    char *title = "From Type, From Name, Edge, To Type, To Name";
    FILE *fPtr;
    fPtr = fopen("edges.csv", "w");
    if (fPtr == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fPtr, "%s\n", title);
    write_edges_file(root);
    fclose(fPtr);
}

void write_edges_file(arbreNode *root)
{
    FILE *fPtr;
    // append
    fPtr = fopen("edges.csv", "a");
    if (fPtr == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    if ((*root->child) != NULL)
    {
        for (int i = 0; i < root->child_num; i++)
        {
            fprintf(fPtr, "arbreNode, %d, NEXT, arbreNode, %d\n", root->data, root->child[i]->data);
            write_edges_file(root->child[i]);
        }
    }
}

void create_arbreNodes_file(arbreNode *root)
{
    char *title = "Type, Name, Description, Image, Reference";
    FILE *fPtr;
    fPtr = fopen("arbreNodes.csv", "w");
    if (fPtr == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fPtr, "%s\n", title);
    write_arbreNodes_file(root);
    fclose(fPtr);
}

void write_arbreNodes_file(arbreNode *root)
{
    int exist_arbreNode[10];
    int exist_number = 0;
    FILE *fPtr;
    // append
    fPtr = fopen("arbreNodes.csv", "a");
    if (fPtr == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    if ((*root->child) != NULL)
    {
        for (int i = 0; i < root->child_num; i++)
        {
            if (appear(exist_arbreNode, root->data) == 0)
            {
                fprintf(fPtr, "arbreNode, %d, NULL, NULL, NULL\n", root->data);
                exist_arbreNode[exist_number] = root->data;
                exist_number++;
            }
            write_arbreNodes_file(root->child[i]);
        }
    }
}

int appear(int array[], int number)
{
    int appear = 0;
    int len = *(&array + 1) - array;
    for (int i = 0; i < len; i++)
    {
        if (number == array[i])
        {
            appear = 1;
        }
    }
    return appear;
}

int **matrixAdjence(arbreNode *root)
{
}