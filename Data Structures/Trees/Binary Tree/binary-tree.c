#include <stdio.h>
#include <stdlib.h>
#include "binary-tree.h"

BinTree* newTree() {
  BinTree* root =  (BinTree*)malloc(sizeof(BinTree));
  if(root != NULL)
    *root = NULL;
  return root;
}

void free_node(BinTree node) {
  if(node == NULL)
    return;
  free_node(node->L);
  free_node(node->R);
  free(node);
  node = NULL;
}

void free_BinTree(BinTree *root) {
  if(root == NULL)
    return;
  free_node(*root);
  free(root);
}

int is_empty_BinTree(BinTree* root) {
  if(root == NULL)
    return 1;
  if(*root == NULL)
    return 1;
  return 0;
}

int height_BinTree(BinTree root) {
  if(root == NULL)
    return 0;
  int L_height = height_BinTree(root->L);
  int R_height = height_BinTree(root->R);
  if(L_height>R_height)
    return (L_height+1);
  else
    return (R_height+1);
}

int total_nodes_BinTree(BinTree* root) {
  if(root == NULL)
    return 0;
  if(*root == NULL)
    return 0;
  int L_height = total_nodes_BinTree(&((*root)->L));
  int R_height = total_nodes_BinTree(&((*root)->R));
  return(L_height + R_height + 1);
}

void pre_order_BinTree(BinTree* root) {
  if(root == NULL)
    return;
  if(*root != NULL){
    printf("%d\n",(*root)->num);
    pre_order_BinTree(&((*root)->L));
    pre_order_BinTree(&((*root)->R));
  }
}

void in_order_BinTree(BinTree* root) {
  if(root == NULL)
    return;
  if(*root != NULL){
    in_order_BinTree(&((*root)->L));
    printf("%d\n",(*root)->num);
    in_order_BinTree(&((*root)->R));
  }
}

void post_order_BinTree(BinTree* root) {
  if(root == NULL)
    return;
  if(*root != NULL){
    post_order_BinTree(&((*root)->L));
    post_order_BinTree(&((*root)->R));
    printf("%d\n",(*root)->num);
  }
}

void printCurrentLevel(BinTree root, int level) {
  if (root == NULL)
    return;
  if (level == 1){
    printf("%d\n", root->num);
  }
  else if (level > 1)
  {
    printCurrentLevel(root->L, level-1);
    printCurrentLevel(root->R, level-1);
  }
}

void breadth_first_search(BinTree root) {
  int h = height_BinTree(root);
  int i;
  for (i=1; i<=h; i++)
    printCurrentLevel(root, i);
}

