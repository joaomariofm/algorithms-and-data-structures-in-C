#include <stdio.h>
#include <stdlib.h>

/**
 * Estruturação de um nó
*/
typedef struct Node{
    int num;
    struct Node * R;
    struct Node * L;
    struct Node * parent;
}Node;
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

/**
 * Diferentes formas de percorrer a Árvore 
*/
/**
 * Pré-Ordem
*/
void pre_order_BinTree(BinTree* root){
    if(root == NULL)
        return;
    if(*root != NULL){
        printf("%d\n",(*root)->num);
        pre_order_BinTree(&((*root)->L));
        pre_order_BinTree(&((*root)->R));
    }
}
/**
 * Em-Ordem
*/
void in_order_BinTree(BinTree* root){
    if(root == NULL)
        return;
    if(*root != NULL){
        in_order_BinTree(&((*root)->L));
        printf("%d\n",(*root)->num);
        in_order_BinTree(&((*root)->R));
    }
}
/**
 * Pós-Ordem
*/
void post_order_BinTree(BinTree* root){
    if(root == NULL)
        return;
    if(*root != NULL){
        post_order_BinTree(&((*root)->L));
        printf("%d\n",(*root)->num);
        post_order_BinTree(&((*root)->R));
    }
}


/**
 * A inserção de nós não foi explorada nessa implementação
 * pois partimos do entendimento de que a inserção de nós 
 * precisa seguir um método, como visto em árvores binárias
 * de busca por exemplo, onde os valores menores que o nó 
 * são inseridos a esquerda e os maiores a direita.
*/