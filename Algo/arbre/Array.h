#include<stdio.h>
#include <stdlib.h>

typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;


void initArray(Array *, size_t);

void insertArray(Array *, int);

void freeArray(Array *);
