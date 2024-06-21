#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct {

	TIPOCHAVE chave;

	// ...
	// outros campos
	// ... 	

} REGISTRO;

typedef struct next {

    REGISTRO reg;
    struct next* prox;

} ELEMENTO;

typedef ELEMENTO* PONTO;

typedef struct {

    PONTO inicio;

} LISTA;

static void inicializarLista(LISTA* lista) {   

	lista->inicio = NULL;
}

static int tamanho(LISTA* lista) {

	PONTO end = lista->inicio;
	int tam = 0;

	while (end != NULL) {
		tam++;
		end = end->prox;
	}

	return tam;
}

static void exibirLista(LISTA* lista) {

	PONTO end = lista->inicio;

	printf("Lista: \" ");

	while(end != NULL) {
		printf("%i ", end->reg.chave);
		end = end->prox;
	}

	printf("\"\n");
}

static PONTO buscaSequencial(LISTA* lista, TIPOCHAVE ch) {

	PONTO pos = lista->inicio;

	while (pos != NULL) {
		if(pos->reg.chave == ch) return pos;
		pos = pos->prox;
	}

	return NULL;   
}

static PONTO buscaSequencialExc(LISTA* lista, TIPOCHAVE ch, PONTO* ant) {

	PONTO atual = lista->inicio;
	*ant = NULL;

	while((atual != NULL) && (atual->reg.chave<ch)) {
		*ant = atual;
		atual = atual->prox;
	}

	if((atual != NULL) && (atual->reg.chave == ch)) return atual;

	return NULL;
}

static int inserirElemListaOrd(LISTA* lista, REGISTRO reg) {

	TIPOCHAVE ch = reg.chave;
	PONTO ant, i;

	i = buscaSequencialExc(lista,ch,&ant);
	
	if(i != NULL) return -1;
	
	i = (PONTO) malloc(sizeof(ELEMENTO));
	i->reg = reg;

	if(ant == NULL) {
		i->prox = lista->inicio;
		lista->inicio = i;
	} else {
		i->prox = ant->prox;
		ant->prox = i;
	}

	return 0;
}

static int excluiElemLista(LISTA* lista, TIPOCHAVE ch) {

	PONTO ant,i;

	i = buscaSequencialExc(lista,ch,&ant);

	if(i == NULL) return -1;
	
	if(ant == NULL) lista->inicio = i->prox;
	
	else ant->prox = i->prox;
	
	free(i);

	return 0;
}

static void reinicializarLista(LISTA* lista) {
    
	PONTO end = lista->inicio;

	while (end != NULL) {

		PONTO apagar = end;
		end = end->prox;
		free(apagar);
	}

	lista->inicio = NULL;
}
