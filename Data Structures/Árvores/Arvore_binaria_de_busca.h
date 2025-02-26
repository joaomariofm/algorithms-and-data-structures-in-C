#include <stdio.h>
#include <stdlib.h>
#include "Arvore_binaria.h"

/**
 * Busca por uma chave específica dentro da árvore
*/
BinTree Tree_Search(BinTree current, int value){
    while(current != NULL && value != current->num){
        if(value < current->num)
            current = current->L;
        else
            current = current->R;
    }

    return current;    
}

/**
 * Busca pelo valor máximo
*/
BinTree Tree_Maximum(BinTree current){
    while(current->R != NULL)
        current = current->R;
    return current;
}

/**
 * Busca pelo valor mínimo
*/
BinTree Tree_Minumun(BinTree current){
    while(current->L != NULL)
        current = current->L;
    return current;
}

/**
 * Encontrar o sucessor de um nó
*/
BinTree Tree_Sucessor(BinTree current){
    if(current->R != NULL)
        return Tree_Minumun(current->R);
    
    BinTree up = current->parent;
    while(up != NULL && current == up->R){
        current = up;
        up = up->parent;
    }
    return up;
}

/**
 * Encontrar o antecessor de um nó
*/
BinTree Tree_Predecessor(BinTree current){
    if(current->L != NULL)
        return Tree_Maximum(current->L);
    
    BinTree up = current->parent;
    while(up != NULL && current == up->L){
        current = up;
        up = up->parent;
    }
    return up;
}

/**
 * Inserção de um nó em uma árvore binária de busca
*/
int Tree_Insert(BinTree* root, int value){
    if(root == NULL)
        return 0;
    Node* new_node;
    new_node = (Node*) malloc(sizeof(Node));
    if(new_node == NULL)
        return 0;
    new_node->num = value;
    new_node->L = NULL;
    new_node->R = NULL;

    //Caso a árvore esteja vazia
    if(*root == NULL)
        *root = new_node;

    //Caso não esteja vazia
    else {
        Node* current = *root;
        Node* previous = NULL;

        while(current != NULL){
            previous = current;

            if(value >= current->num)
                current = current->R;
            else 
                current = current->L;
        }

        new_node->parent = previous;

        if(value > previous->num)
            previous->R = new_node;
        else 
            previous->L = new_node;
    }
    return 1;
}
/**
 * Eleminação de um nó em uma árvore binária de buca
*/
void Transplant(BinTree* root,Node* u,Node* v){
    if(u->parent == NULL)
        *root = v;
    else if(u == u->parent->L)
        u->parent->L = v;
    else   
        u->parent->R = v;
    
    if(v != NULL)
        v->parent = u->parent;
}

void Tree_Delete(BinTree* root, Node* node_removed){
    Node* y;

    if(node_removed->L == NULL)
        Transplant(root,node_removed,node_removed->R);
    else if(node_removed->R == NULL)
        Transplant(root,node_removed,node_removed->L);
    else{
        y = Tree_Minumun(node_removed->R);

        if(y->parent != node_removed){
            Transplant(root,y,y->R);
            y->R = node_removed->R;
            y->R->parent = y;
        }

        Transplant(root,node_removed,y);
        y->L = node_removed->L;
        y->L->parent = y;
    }

    free(node_removed);
}