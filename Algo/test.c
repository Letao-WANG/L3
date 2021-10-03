#include <stdio.h>
#include <stdlib.h>

void swap(int **a, int *b)
{
    int *c = *a;
    int tmp = *c;
    *c = *b;
    *b = tmp;
}

int main()
{
    int a = 1;
    int *pa = &a;

    int b = 2;
    swap(&pa, &b);
    printf("a : %d, b %d\n", a, b);
}
