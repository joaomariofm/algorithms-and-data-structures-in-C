#include <stdio.h>
#include <stdlib.h>

void inicializarFila(FILA* f){
    f->inicio = NULL;
    f->fim = NULL;
}

int tamanho(FILA* f){
    PONT end = f->inicio;
    int tam = 0;
    while(end != NULL){
        tam++;
        end = end->prox;
    }
    return tam;
}

void exibirFila(FILA* f){
    PONT end = f->inicio;
    printf("Fila: \" ");
    while(end != NULL){
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

int inserirNaFila(FILA* f,REGISTRO reg){
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = NULL;
    if(f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;
        f->fim =novo;
    return 0;
}

int excluirDaFila(FILA* f, REGISTRO* reg){
    if(f->inicio == NULL)
        return 1;
    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    if(f->inicio == NULL)
        f->fim = NULL;
    return 0;
}

void reinicializarFila(FILA* f){
    PONT end = f->inicio;
    while(end != NULL){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    f->inicio = NULL;
    f->fim = NULL;
}
