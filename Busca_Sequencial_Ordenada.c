#include <stdio.h>

/**
 * Observação:
 *  A Busca Sequencial Ordenada assime que o
 *  array já está organizado quando inicia sua execução
*/

int buscaOrdenada(int *V, int N, int elem) {
    int i;
    for(i = 0 ; i<N ; i++) {
        if(elem == V[i])
            return i;//elemento encontrado
        else    
            if(elem > V[i])
                return -1;//para a busca
    }
    return -1;//elemento não encontrado
}