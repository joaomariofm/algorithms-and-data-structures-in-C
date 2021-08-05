#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    //outros campos
} REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* ant;
    struct aux* prox;
} ELEMENTO,*PONT;

typedef struct{
    PONT cabeca;
} DEQUE;

void inicializarDeque(DEQUE* d){
    d->cabeca = (PONT)malloc(sizeof(ELEMENTO));
    d->cabeca->prox = d->cabeca;
    d->cabeca->ant = d->cabeca;
}

int tamanho(DEQUE* d){
    PONT end = d->cabeca->prox;
    int tam = 0;
    while(end != d->cabeca){
        tam++;
        end = end->prox;
    }
    return tam;
}

/**
 * Por ser um deque, percorrelo em sentido
 * horário ou anti-horário não faz diferença
*/
/* int tamanho(DEQUE* d){
    PONT end = d->cabeca->ant;
    int tam = 0;
    while(end != d->cabeca){
        tam++;
        end = end->ant;
    }
    return tam;
} */

void exibirDequeFim(DEQUE* d){
    PONT end = d->cabeca->ant;
    printf("Deque partindo do fim: \" ");
    while(end != d->cabeca){
        printf("%i ", end->reg.chave);
        end = end->ant;
    }
    printf("\"\n");
}

int inserirDequeFim(DEQUE* d,REGISTRO reg){
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = d->cabeca;
    novo->ant = d->cabeca->ant;
    d->cabeca->ant = novo;
    novo->ant->prox = novo;
    return 0;
}

int excluirElemDequeInicio(DEQUE* d,REGISTRO* reg){
    if(d->cabeca->prox == d->cabeca)
        return 1;
    PONT apagar = d->cabeca->prox;
    /**
     * O registro apagado é transferido para o
     * registro vazia passado como parâmetro
    */
    *reg = apagar->reg;
    d->cabeca->prox = apagar->prox;
    apagar->prox->ant = d->cabeca;
    free(apagar);
    return 0;
}

void reinicializarDeque(DEQUE* d){
    PONT end = d->cabeca->prox;
    while(end != d->cabeca){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    d->cabeca->prox = d->cabeca;
    d->cabeca->ant = d->cabeca;
}