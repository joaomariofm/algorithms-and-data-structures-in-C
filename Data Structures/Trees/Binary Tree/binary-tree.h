#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int num;
  struct Node * R;
  struct Node * L;
  struct Node * parent;
}Node;

typedef struct Node *BinTree;

BinTree* newTree();

void free_node(BinTree node);

void free_BinTree(BinTree *root);

int is_empty_BinTree(BinTree* root);

int height_BinTree(BinTree root);

int total_nodes_BinTree(BinTree* root);

void pre_order_BinTree(BinTree* root);

void in_order_BinTree(BinTree* root);

void post_order_BinTree(BinTree* root);

void printCurrentLevel(BinTree root, int level);

void breadth_first_search(BinTree root);

/**
 * A inserção de nós não foi explorada nesse arquivo
 * pois partimos do entendimento de que a inserção de nós 
 * precisa seguir um método, como visto em árvores binárias
 * de busca por exemplo, onde os valores menores que o nó 
 * são inseridos a esquerda e os maiores a direita.
*/
