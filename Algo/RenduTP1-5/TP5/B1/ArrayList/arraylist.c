#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "arraylist.h"

#define ARRAYLIST_INITIAL_CAPACITY 4

arraylist* arraylist_create()
{
	arraylist* new_list = malloc(sizeof(arraylist));
	new_list->size = 0;
	new_list->body = malloc(sizeof(void*) * ARRAYLIST_INITIAL_CAPACITY);
	assert(new_list->body);
	new_list->capacity = ARRAYLIST_INITIAL_CAPACITY;
	return new_list;
}

void arraylist_allocate(arraylist* l, unsigned int size)
{
	assert(size > 0);
	if (size > l->capacity) {
		unsigned int new_capacity = l->capacity;
		while (new_capacity < size) {
			new_capacity *= 2;
		}
		l->body = realloc(l->body, sizeof(void*) * new_capacity);
		assert(l->body);
		l->capacity = new_capacity;
	}
}

unsigned int arraylist_size(arraylist*l) {
	return l->size;
}

void arraylist_add(arraylist* l, void* item)
{
	arraylist_allocate(l, l->size + 1);
	l->body[l->size++] = item;
}

void* arraylist_get(arraylist* l, unsigned int index)
{
	assert(index < l->size);
	return l->body[index];
}

void arraylist_destroy(arraylist* l)
{
	free(l->body);
	free(l);
}