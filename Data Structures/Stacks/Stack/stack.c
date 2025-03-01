#include <stdio.h>
#include <stdlib.h>

void inicializarPilha(PILHA* p){
  p->topo = NULL;
}

int tamanho(PILHA* p){
  PONT end = p->topo;
  int tam = 0;
  while(end != NULL){
    tam++;
    end = end->prox;
  }
  return tam;
}

int estaVazia(PILHA* p){
  if(p->topo == NULL)
    return 0;
  return 1;
}

void exibirPilha(PILHA* p){
  PONT end = p->topo;
  printf("Pilha: \" ");
  while(end != NULL){
    printf("%i ", end->reg.chave);
    end = end->prox;
  }
  printf("\"\n");
}

int inserirElemPilha(PILHA* p, REGISTRO reg){
  PONT novo = (PONT)malloc(sizeof(ELEMENTO));
  novo->reg = reg;
  novo->prox = p->topo;
  p->topo = novo;
  return 0;
}

int excluirElemPilha(PILHA* p,REGISTRO* reg){
  if(p->topo == NULL)
    return 1;
  *reg = p->topo->reg;
  PONT apagar = p->topo;
  p->topo = p->topo->prox;
  free(apagar);
  return 0;
}

void reinicializarPilha(PILHA* p){
  PONT apagar;
  PONT posicao = p->topo;
  while(posicao = NULL){
    apagar = posicao;
    posicao = posicao->prox;
    free(apagar);
  }

  p->topo = NULL;
}
