#include <stdio.h>
#include <stdlib.h>
#include "../Binary Tree/binary-tree.h"

/**
 * Busca por uma chave específica dentro da árvore
*/
BinTree Tree_Search(BinTree current, int value);

/**
 * Busca pelo valor máximo
*/
BinTree Tree_Maximum(BinTree current);

/**
 * Busca pelo valor mínimo
*/
BinTree Tree_Minumun(BinTree current);

/**
 * Encontrar o sucessor de um nó
*/
BinTree Tree_Sucessor(BinTree current);

/**
 * Encontrar o antecessor de um nó
*/
BinTree Tree_Predecessor(BinTree current);

/**
 * Inserção de um nó em uma árvore binária de busca
*/
int Tree_Insert(BinTree* root, int value);

/**
 * Eleminação de um nó em uma árvore binária de buca
*/
void Transplant(BinTree* root,Node* u,Node* v);

void Tree_Delete(BinTree* root, Node* node_removed);

