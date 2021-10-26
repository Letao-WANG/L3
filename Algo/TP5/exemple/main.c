#include <stdlib.h>
#include <stdio.h>
#include "node.h"


int main()
{
  struct Node *root = NULL;

  for(int i=0; i<10;i++){
      root = insert(root, i);
  }
 
  preOrder(root);
 
  return 0;
}