#include <stdio.h>
#include <stdlib.h>
#include "../Heaps/Max_Heap.h"

int HeapMax(int* A){
    return A[0];
}

int HeapExtractMax(HEAP* h){
    int temp;

    if(h->tamanhoAtual < 0)
        return NULL;
    
    int max = HeapMax(h->A);

    temp = h->A[0];
    h->A[0] = h->A[h->tamanhoAtual - 1];
    h->A[h->tamanhoAtual - 1] =temp;

    (h->tamanhoAtual)--;

    ReHeapDown(h,0);

    return max;
}

void HeapIncreaseKey(HEAP* h, int i, int chave){

    if(chave < h->A[i])
        return;

    h->A[i] = chave;

    ReHeapDown(h,0);
}

void MaxHeapInsert(HEAP* h, int chave){
    h->A[h->tamanhoAtual] = chave;
    
    ReHeapUp(h,h->tamanhoAtual);
    (h->tamanhoAtual)++;
}
