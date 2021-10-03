#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void ll_init(ll_s **node, int data)
{
    (*node) = (ll_s *)malloc(sizeof(ll_s));
    (*node)->data = data;
    (*node)->prev = NULL;
    (*node)->next = NULL;
}

void ll_insert(ll_s **node, int data)
{
    if (node != NULL && *node != NULL)
    {
        ll_s *new_node;
        ll_init(&new_node, data);
        (*node)->next = new_node;
        new_node->prev = *node;
    }
}

void ll_delete(ll_s **node)
{
    if ((*node)->prev == NULL && (*node)->next == NULL)
    {
        *node = NULL;
    }
    else if (node != NULL && *node != NULL)
    {
        ll_s *cur_node = *node;
        ll_s *prev_node = cur_node->prev;
        ll_s *next_node = cur_node->next;
        if (prev_node != NULL)
        {
            prev_node->next = next_node;
        }
        if (next_node != NULL)
        {
            next_node->prev = prev_node;
        }
        free(cur_node);
        cur_node = NULL;
        if (next_node != NULL)
        {
            *node = next_node;
        }
        else if ( prev_node != NULL)
        {
            *node = prev_node;
            (*node)->next = NULL;
        }
    }
}

void ll_deleteFirst(ll_s **node)
{
    *node = ll_firstNode(*node);
    ll_delete(node);
}

ll_s *ll_lastNode(ll_s *root)
{
    while (root)
    {
        if (root->next == NULL)
            return root;
        else
            root = root->next;
    }
    return root;
}

ll_s *ll_firstNode(ll_s *root)
{
    if(root == NULL)
        return NULL;
    while (root)
    {
        if (root->prev == NULL)
            return root;
        else
            root = root->prev;
    }
    return root;
}

void ll_view(ll_s *root)
{
    while (root != NULL)
    {
        printf("%d", root->data);
        root = root->next;
    }
    printf("\n");
}