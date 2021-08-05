#include <stdio.h>
#include <stdlib.h>

typedef int boll;
/**
 * false = -1
 * true = 0
*/
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    //outros campos
} REGISTRO;

/**
 * aux é do tipo elemento 
 * ou seja 
 * cada elemento possui em si o endreço (por isso o *)
 * do próximo elemento, seu sucessor 
*/
typedef struct aux
{
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

/**
 * O tipo PONTO armazena o endereço de um elemento
*/
typedef ELEMENTO* PONT;

typedef struct 
{
    PONT inicio;
} LISTA;

void inicializarLista(LISTA* lista)
{   
    lista->inicio = NULL;
}

int tamanho(LISTA* lista)
{
    PONT end = lista->inicio;
    int tam = 0;
    while (end != NULL)
    {
        tam++;
        end = end->prox;
    }
    return tam;
}

void exibirLista(LISTA* lista)
{
    PONT end = lista->inicio;
    printf("Lista: \" ");
    while(end != NULL)
    {
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

PONT buscaSequencial(LISTA* lista, TIPOCHAVE ch)
{
    PONT pos = lista->inicio;
    while (pos != NULL)
    {
        if(pos->reg.chave == ch) return pos;
        pos = pos->prox;
    }
    return NULL;   
}

PONT buscaSequencialExc(LISTA* lista, TIPOCHAVE ch, PONT* ant)
{
    //endereço do que será o elemnto anterior
    *ant = NULL;
    PONT atual = lista->inicio;
    /**
     * Usando a variavel chave para organizar os registros
     * dessa forma os registros da lista serão organizados 
     * em ordem crescente
    */
    while((atual != NULL) && (atual->reg.chave<ch))
    {
        /**
         * Percorre a lista e acha o que podera ser 
         * o endereço do registro anterior ao novo registro
         * 
         * E loop garante a ordenação dos elementos em ordem 
         * crescente
        */
        *ant = atual;
        atual = atual->prox;
    }
    if((atual != NULL) && (atual->reg.chave == ch)) return atual;
    return NULL;
}

boll inserirElemListaOrd(LISTA* lista, REGISTRO reg)
{
    TIPOCHAVE ch = reg.chave;
    PONT ant, i;
    i = buscaSequencialExc(lista,ch,&ant);
    /**
     * A função deve retornar um valor NULL
    */
    if(i != NULL) return -1;
    /**
     * i receberá o endereço do novo registro
    */
    i = (PONT) malloc(sizeof(ELEMENTO));
    i->reg = reg;
    if(ant == NULL)
    {
        /**
         * Nesse caso o novo elemento será o primeiro 
         * elemento da lista
         * então seu sucessor será o que antes era o primeiro
         * elento da lista e o inicio da lista receberá o 
         * endereço desse elemento
        */
        i->prox = lista->inicio;
        lista->inicio = i;
    }else{
        /**
         * Nesse caso i será inserido entre dois elementos
         * então o sucessor de seu antecessor se tornará o 
         * sucessor de i, e i se tornará o sucessor de seu
         * antecessor
        */
        i->prox = ant->prox;
        ant->prox = i;
    }
    return 0;
}

boll excluiElemLista(LISTA* lista, TIPOCHAVE ch)
{
    PONT ant,i;
    i = buscaSequencialExc(lista,ch,&ant);
    if(i == NULL) return -1;
    /**
     * Nesse primeiro caso o elemento que foi procurado
     * é o primeiro elemento da lista, então basta fazer
     * com que a lista passe a ser iniciada pelo segundo 
     * elemento
    */
    if(ant == NULL) lista->inicio = i->prox;
    /**
     * Nesse segundo caso o elmento procurado está entre 
     * dois registros então basta fazer com que o sucessor
     * do elemento procurado passe a ser o sucessor so antecessor
     * do elemento procurado
    */
    else ant->prox = i->prox;
    /**
     * De qualquer forma o elemento que foi encontrado será
     * apagado da memória
    */
    free(i);
    return 0;
}

void reinicializarLista(LISTA* lista)
{
    /**
     * A reinicialização da lista consiste em apagar
     * todos os seus registros e setar o seu início
     * para NULL
    */
    PONT end = lista->inicio;
    while (end != NULL)
    {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    lista->inicio = NULL;
}