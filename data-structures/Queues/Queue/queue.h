#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    //outros campos
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO, *PONT;

typedef struct {
    PONT inicio;
    PONT fim;
} FILA;

void inicializarFila(FILA* f);

int tamanho(FILA* f);

void exibirFila(FILA* f);

int inserirNaFila(FILA* f,REGISTRO reg);

int excluirDaFila(FILA* f, REGISTRO* reg);

void reinicializarFila(FILA* f);
