#include <stdio.h>
#include <stdlib.h>
#include "listedouble.h"

dll_s *dll_new(void)
{
    return (NULL);
}
void dll_insert(dll_s **pp_dll, void *data)
{
    if (pp_dll != NULL)
    {
        dll_s *p_p = *pp_dll;
        dll_s *p_l = NULL;
        dll_s *p_n = NULL;
        if (p_p != NULL)
            p_n = p_p->next;
        p_l = malloc(sizeof(*p_l));
        if (p_l != NULL)
        {
            p_l->data = data;
            p_l->next = p_n;
            if (p_n != NULL)
                p_n->prev = p_l;
            p_l->prev = p_p;
            if (p_p != NULL)
                p_p->next = p_l;
            // *pp_dll = p_l;
        }
        else
        {
            fprintf(stderr, "Memoire insuffisante\n");
            exit(EXIT_FAILURE);
        }
    }
}
void dll_remove(dll_s **pp_dll)
{
    if (pp_dll != NULL && *pp_dll != NULL)
    {
        dll_s *p_l = *pp_dll;
        dll_s *p_p = p_l->prev;
        dll_s *p_n = p_l->next;
        if (p_p != NULL)
            p_p->next = p_n;
        if (p_n != NULL)
            p_n->prev = p_p;
        free(p_l);
        p_l = NULL;
        if (p_n != NULL)
            *pp_dll = p_n;
        else
            *pp_dll = p_p;
    }
}
void dll_next(dll_s **pp_dll)
{
    if (pp_dll != NULL && *pp_dll != NULL)
        *pp_dll = (*pp_dll)->next;
}
void dll_prev(dll_s **pp_dll)
{
    if (pp_dll != NULL && *pp_dll != NULL)
        *pp_dll = (*pp_dll)->prev;
}
void *dll_data(dll_s *p_dll)
{
    return ((p_dll != NULL) ? p_dll->data : NULL);
}
void dll_first(dll_s **pp_dll)
{
    if (pp_dll != NULL && *pp_dll != NULL)
    {
        while ((*pp_dll)->prev != NULL)
            dll_prev(pp_dll);
    }
}
void dll_last(dll_s **pp_dll)
{
    if (pp_dll != NULL && *pp_dll != NULL)
    {
        while ((*pp_dll)->next != NULL)
            dll_next(pp_dll);
    }
}
size_t dll_sizeof(dll_s *p_dll)
{
    size_t n = 0;
    if (p_dll != NULL)
    {
        dll_first(&p_dll);
        while (p_dll != NULL)
        {
            n++;
            dll_next(&p_dll);
        }
    }
    return (n);
}
void dll_delete(dll_s **pp_dll)
{
    if (pp_dll != NULL && *pp_dll != NULL)
    {
        dll_first(pp_dll);
        while (*pp_dll != NULL)
            dll_remove(pp_dll);
    }
}
void view(dll_s * dll)
{
    while (dll)
    {
        printf("%d\n", *((int*)dll->data));
        dll = dll->next;
    }
}
