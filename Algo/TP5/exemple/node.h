#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

int max(int, int);
 
int height(struct Node *);
 
int max(int a, int b);
 
struct Node* newNode(int);
 
struct Node *rightRotate(struct Node *);
 
struct Node *leftRotate(struct Node *);
int getBalance(struct Node *);
 
struct Node* insert(struct Node*, int);
 
void preOrder(struct Node *);
 