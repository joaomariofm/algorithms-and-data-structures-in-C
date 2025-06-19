/******************************************************************************/
/*              Este programa gerencia arvores AVL                            */
/*  Arvores AVL sao arvores balanceadas na altura.                            */
/*  O nome AVL vem de seus criadores Adelson Velsky e Landis, cuja primeira   */
/*    referência encontra-se no documento "Algoritmos para organização da     */
/*    informação" de 1962.                                                    */
/******************************************************************************/

#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0

typedef int TIPOCHAVE;

typedef struct aux {
	TIPOCHAVE chave;
	struct aux *esq;
	struct aux *dir;
	int bal; // fator de balanceamento (0, -1 ou +1) => alt. direita - alt. esquerda
} NO, *PONT;

PONT criarNovoNo(TIPOCHAVE ch);

int max(int a, int b);

int altura(PONT p);

void exibirArvoreEmOrdem(PONT raiz);

void exibirArvorePreOrdem(PONT raiz);

void exibirArvorePosOrdem(PONT raiz);

void exibirArvore(PONT raiz);

void exibirArvore2(PONT raiz, TIPOCHAVE chavePai);

int height_BinTree(PONT root);

void printCurrentLevel(PONT root, int level);

void breadth_first_search(PONT root);

int ehAVL(PONT p);

int ehAVL2(PONT p, int* alt);

int atualizarBalanceamentoTotal(PONT raiz);

PONT rotacaoL(PONT p);

PONT rotacaoR(PONT p);

void inserirAVL(PONT* pp, TIPOCHAVE ch, int* alterou);

PONT buscaBinaria(TIPOCHAVE ch, PONT raiz); 

PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai);

PONT maiorAEsquerda(PONT p, PONT *ant);

int excluirAVL(PONT* raiz, TIPOCHAVE ch, int* alterou);

void destruirAux(PONT subRaiz);

void destruirArvore(PONT * raiz);

void inicializar(PONT * raiz);

void travessiaAux(PONT p, int *niv, TIPOCHAVE ch, int *achou);

int travessia(PONT p, int *niv, TIPOCHAVE ch);

