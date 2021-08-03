#include <stdio.h>
#include <stdlib.h>

/**
 * Estruturação de um nó
*/
struct Node{
    int num;
    struct Node * R;
    struct Node * L;
};
/**
 * Ponteiro para o nó raiz
*/
typedef struct Node *BinTree;

/**
 * Criação de uma nova árvore
*/
BinTree* newTree() {
    BinTree* root =  (BinTree*)malloc(sizeof(BinTree));
    if(root != NULL)
        *root = NULL;
    return root;
}

/**
 * Destruição da árvore
*/
void free_node(BinTree node){
    if(node == NULL)
        return;
    free_node(node->L);
    free_node(node->R);
    free(node);
    node = NULL;
}

void free_BinTree(BinTree *root){
    if(root == NULL)
        return;
    free_node(*root);
    free(root);
}

/**
 * Função que verifica se a árvore está vazia
*/
int is_empty_BinTree(BinTree* root){
    if(root == NULL)
        return 1;
    if(*root == NULL)
        return 1;
    return 0;
}

/**
 * Função que verifica a altura da árvore
*/
int height_BinTree(BinTree* root){
    if(root == NULL)
        return 0;
    if(*root == NULL)
        return 0;
    int L_height = height_BinTree(&((*root)->L));
    int R_height = height_BinTree(&((*root)->R));
    if(L_height>R_height)
        return (L_height+1);
    else
        return (R_height+1);
}

/**
 * Função que verifica a quantidade de nós da árvore
*/
int total_nodes_BinTree(BinTree* root){
    if(root == NULL)
        return 0;
    if(*root == NULL)
        return 0;
    int L_height = total_nodes_BinTree(&((*root)->L));
    int R_height = total_nodes_BinTree(&((*root)->R));
    return(L_height + R_height + 1);
}

int main(void) {
    BinTree *root = newTree();

    printf("%i\n", is_empty_BinTree(root));

    return 0;
}