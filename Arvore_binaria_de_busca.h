#include <stdio.h>
#include <stdlib.h>
#include "Arvore_binaria.h"

int insert_BinTree(BinTree* root, int value){
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
        if(value > previous->num)
            previous->R = new_node;
        else 
            previous->L = new_node;
    }

    return 1;
}