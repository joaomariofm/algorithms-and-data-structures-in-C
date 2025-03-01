#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
} REGISTRO;

typedef struct aux{
  REGISTRO reg;
  struct aux* prox;
} ELEMENTO, *PONT;

typedef struct {
  PONT topo;
} PILHA;

void inicializarPilha(PILHA* p);

int tamanho(PILHA* p);

int estaVazia(PILHA* p);

void exibirPilha(PILHA* p);

int inserirElemPilha(PILHA* p, REGISTRO reg);

int excluirElemPilha(PILHA* p,REGISTRO* reg);

void reinicializarPilha(PILHA* p);
