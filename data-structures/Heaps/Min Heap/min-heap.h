#include <malloc.h>
#include <stdio.h>
#define true 1
#define false 0

typedef struct {
  int * A;
  int tamanhoAtual;
  int tamanhoMaximo;
} HEAP;

void inicializarHeap(HEAP * h, int tamanhoMax);

void destruirHeap(HEAP * h);

int pai(int i);

int filhoEsquerda(int i);

int filhoDireita(int i);

void ReHeapUp(HEAP* h, int i);

void Insert(HEAP* h, int valor);

void ReHeapDown(HEAP* h,int i);

void Delete_MaxVal(HEAP* h);

HEAP* Heapfy(int* A,int n);

void HeapSort(int* A, int n);

void imprimirHeapArray(HEAP h);

void imprimirArray(int* A,int n);

int percursoPreOrdem(HEAP* h, int atual);

int alturaHeap(HEAP* h);

