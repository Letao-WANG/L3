#include <stdio.h>
#include <stdlib.h>

typedef struct arraylist {
	unsigned int size;
	unsigned int capacity; 
	void** body; 
} arraylist;

void arraylist_destroy(arraylist *);
void *arraylist_get(arraylist *,unsigned int);
void arraylist_add(arraylist *,void *);
unsigned int arraylist_size(arraylist *l);
void arraylist_allocate(arraylist *,unsigned int);
arraylist *arraylist_create();