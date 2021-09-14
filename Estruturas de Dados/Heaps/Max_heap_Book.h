#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int * A;
  int tamanhoAtual;
  int tamanhoMaximo;
} HEAP;

void inicializarHeap(HEAP * h, int tamanhoMax){
  h->A = (int*) malloc(sizeof(int)*(tamanhoMax+1));
  h->tamanhoAtual = 0;
  h->tamanhoMaximo = tamanhoMax;
}

void destruirHeap(HEAP * h){
  int tamanho = h->tamanhoMaximo;
  free(h->A);
  h->tamanhoMaximo=0;
  h->tamanhoAtual=0;
}

int pai(int i){
  return (i-1)/2;
}

int filhoEsquerda(int i){
  return 2*i + 1;
}

int filhoDireita(int i){
  return 2*i + 2;
}

void MaxHeapify(HEAP* h, int i){
    int l = filhoEsquerda(i);
    int r = filhoDireita(i);

    int maior;
    int temp;

    if(l <= h->tamanhoAtual && h->A[l] > h->A[i])
        maior = l;
    else  
        maior = i;

    if (r <= h->tamanhoAtual && h->A[r] > h->A[maior])
        maior = r;
    
    if(maior != i){
        temp = h->A[i];
        h->A[i] = h->A[maior];
        h->A[maior] = temp;

        MaxHeapify(h,maior);
    }
}

void BuilMaxHeap(int *A,int n){
    HEAP* h = (HEAP*)malloc(sizeof(HEAP));
    inicializarHeap(h,n);
    h->A = A;
    h->tamanhoAtual = n;
    h->tamanhoMaximo = n;

    int i;
    for(i = (n-1)/2 ; i > 0 ; i--)
        MaxHeapify(h,i);
}

// Imprime o arranjo (na ordem que estiver)
void imprimirHeapArray(HEAP h){
  int tamanho = h.tamanhoAtual;
  int i;
  for (i=0;i<tamanho;i++) printf("%d ",h.A[i]);
  printf("\n");
}

void imprimirArray(int* A,int n){
    int i;
    
    for(i = 0 ; i<n ; i++){
        printf("%d ",A[i]);
    }
        
    printf("\n");
}