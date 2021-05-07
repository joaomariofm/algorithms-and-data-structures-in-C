#include <stdio.h>

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