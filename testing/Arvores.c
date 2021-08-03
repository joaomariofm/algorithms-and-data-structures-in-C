#include <stdlib.h>
#include <stdio.h>
#include "../Arvore_binaria_de_busca.h"

int main(void){
    //Nova raiz
    BinTree* root = newTree();

    insert_BinTree(root,2);
    insert_BinTree(root,5);
    insert_BinTree(root,7);
    insert_BinTree(root,6);
    insert_BinTree(root,8);
    insert_BinTree(root,3);

    in_order_BinTree(root);
}