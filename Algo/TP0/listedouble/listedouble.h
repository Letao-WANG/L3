#ifndef H_LISTEDOUBLE
#define H_LISTEDOUBLE
#include <stddef.h> /* pour size_t */
typedef struct dll
{
    struct dll *prev;
    struct dll *next;
    void *data;
} dll_s;
dll_s *dll_new(void);
void dll_insert(dll_s **, void *);
void dll_remove(dll_s **);
void dll_prev(dll_s **);
void dll_next(dll_s **);
void *dll_data(dll_s *);
void dll_first(dll_s **);
void dll_last(dll_s **);
size_t dll_sizeof(dll_s *);
void dll_delete(dll_s **);
void view(dll_s *);
#endif /* not H_LISTEDOUBLE */