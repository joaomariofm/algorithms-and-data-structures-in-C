#include <stdio.h>
#include <malloc.h>
#include "avl-tree.h"

#define true 1
#define false 0

PONT criarNovoNo(TIPOCHAVE ch) {
	PONT novoNo = (PONT)malloc(sizeof(NO));
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	novoNo->chave = ch;
	novoNo->bal = 0;
	return novoNo;
}

// Retorna o maior valor entre dois inteiros
int max(int a, int b) {
	if (a>b) return a;
	return b;
}

// Retorna a altura de uma (sub-)arvore
int altura(PONT p) {
	if (!p) return -1;
	else return 1 + max(altura(p->esq),altura(p->dir));
}


/* Exibe arvore Em Ordem */
void exibirArvoreEmOrdem(PONT raiz) {
	if (raiz == NULL) return;
	exibirArvoreEmOrdem(raiz->esq);
	printf("%i ",raiz->chave);
	exibirArvoreEmOrdem(raiz->dir);
}

/* Exibe arvore Pre Ordem */
void exibirArvorePreOrdem(PONT raiz) {
	if (raiz == NULL) return;
	printf("%i ",raiz->chave);
	exibirArvorePreOrdem(raiz->esq);
	exibirArvorePreOrdem(raiz->dir);
}

/* Exibe arvore Pos Ordem */
void exibirArvorePosOrdem(PONT raiz) {
	if (raiz == NULL) return;
	exibirArvorePreOrdem(raiz->esq);
	exibirArvorePreOrdem(raiz->dir);
	printf("%i ",raiz->chave);
}

/* Exibe arvore Em Ordem (com parenteses para os filhos) */
void exibirArvore(PONT raiz) {
	if (raiz == NULL) return;
	printf("%i[%i]",raiz->chave,raiz->bal);
	printf("(");     
	exibirArvore(raiz->esq);
	exibirArvore(raiz->dir);
	printf(")");     
}

/* Exibe arvore Pre-Ordem indicando pai de cada no */
void exibirArvore2(PONT raiz, TIPOCHAVE chavePai) {
	if (raiz == NULL) return;
	printf("(%i,%i) ",chavePai,raiz->chave);
	exibirArvore2(raiz->esq,raiz->chave);
	exibirArvore2(raiz->dir,raiz->chave);
}

/* Exibi Árvore por nível */
int height_BinTree(PONT root) {
    if(root == NULL)
        return 0;
    int L_height = height_BinTree(root->esq);
    int R_height = height_BinTree(root->dir);
    if(L_height>R_height)
        return (L_height+1);
    else
        return (R_height+1);
}

void printCurrentLevel(PONT root, int level) {

    if (root == NULL)
        return;
    if (level == 1){
        printf("%d ", root->chave);
    }
    else if (level > 1)
    {
        printCurrentLevel(root->esq, level-1);
        printCurrentLevel(root->dir, level-1);
    }
}

void breadth_first_search(PONT root) {
    int h = height_BinTree(root);
    int i;
    for (i=1; i<=h; i++){
        printCurrentLevel(root, i);
        printf("\n");
    }
}

// Verifica se árvore é AVL
int ehAVL(PONT p) {
	int e,d;
	int ok = true;
	if(p){
		ok = ehAVL(p->esq);
		if(ok) ok = ehAVL(p->dir);
		if(ok){
			e = altura(p->esq);
			d = altura(p->dir);
			if(e-d > 1 || e-d < -1) ok = false;  
			else ok = true;
		}
	}
	return(ok);
}

// Verifica se árvore é AVL
int ehAVL2(PONT p, int* alt) {
    if (!p){
       *alt=-1;
       return true;
    }
    int res;
    int d, e;
    res = ehAVL2(p->dir,&d);
    if (!res) return false;
    res = ehAVL2(p->esq,&e);
    if (!res) return false;
    if (d-e != p->bal) printf("### O campo 'bal' do no '%i' esta com valor incorreto de balanceamento. ###\n",p->chave);
    if ((d-e<-1) || (d-e>1)) return false;
	*alt = max(d,e)+1; 
	return true;	
}

int atualizarBalanceamentoTotal(PONT raiz) {
	if (!raiz) return 0;
	int d = atualizarBalanceamentoTotal(raiz->dir);
	int e = atualizarBalanceamentoTotal(raiz->esq);
	raiz->bal = d-e;
	return max(d,e)+1;
}

/* Rotações à direita (LL e LR) Retornará o endereço do nó que será a nova raiz da subárvore originalmente iniciada por p */
PONT rotacaoL(PONT p) {
	//printf("Rotacao a esquerda, problema no no: %i\n",p->chave);
	PONT u, v;
	u = p->esq;
	if(u->bal == -1) {   // LL
		p->esq = u->dir;
		u->dir = p;
		p->bal = 0;
		u->bal = 0;
		return u;
	} else if (u->bal == 1) {  // LR
		v = u->dir;
		u->dir = v->esq;
		v->esq = u;
		p->esq = v->dir;
		v->dir = p;
		if(v->bal == -1) p->bal = 1;
		else p->bal = 0;
		if(v->bal == 1) u->bal = -1;
		else u->bal = 0;
		v->bal = 0;
		return v;
	}else{   // caso necessario apenas para a exclusao (u->bal == 0)
		p->esq = u->dir;
		u->dir = p;
		// p->bal = -1;    desnecessario pois o balanceamento de p nao chegou a ser mudado para -2
		u->bal = 1;
		return u;
	}
}

/* Rotações à esquerda (RR e RL) Retornará o endereço do nó que será a nova raiz da subárvore originalmente iniciada por p */
PONT rotacaoR(PONT p) {
	//printf("Rotacao a direita, problema no no: %i\n",p->chave);
	PONT u, v;
	u = p->dir;
	if(u->bal == 1) {   // RR
		p->dir = u->esq;
		u->esq = p;
		p->bal = 0;
		u->bal = 0;
		return u;
	} else if (u->bal == -1){  // RL
		v = u->esq;
		u->esq = v->dir;
		v->dir = u;
		p->dir = v->esq;
		v->esq = p;
		if(v->bal == 1) p->bal = -1;
		else p->bal = 0;
		if(v->bal == -1) u->bal = 1;
		else u->bal = 0;
		v->bal = 0;
		return v;
	}else{   // caso necessario apenas para a exclusao (u->bal == 0)
		p->dir = u->esq;
		u->esq = p;
		u->bal = -1;
		// p->bal = 1;    desnecessario pois o balanceamento de p nao chegou a ser mudado para 2
		return u;	
	}
}

/* Inserção AVL: p é inicializado com o endereco do nó raiz e alterou com false */
void inserirAVL(PONT* pp, TIPOCHAVE ch, int* alterou) {
	PONT p = *pp;
	if(!p){
		*pp = criarNovoNo(ch);
		*alterou = true;
	} else {
if(ch == p->chave) *alterou = false;
		else if(ch <= p->chave) {
			inserirAVL(&(p->esq), ch, alterou);
			if(*alterou)
				switch (p->bal) {
					case 1 : p->bal = 0;
					*alterou = false;
					break;
					case 0 : p->bal = -1;
					break;
					case -1: *pp = rotacaoL(p);
					*alterou = false;
					break;
				}
		} else {
			inserirAVL(&(p->dir), ch, alterou);
			if(*alterou)
				switch (p->bal) {
					case -1: p->bal = 0;
					*alterou = false;
					break;
					case 0 : p->bal = 1;
					break;
					case 1 : *pp = rotacaoR(p);
					*alterou = false;
					break;
				}
		}
	}
}

/* retorna o endereco do NO que contem chave=ch ou NULL caso a chave nao seja encontrada. Utiliza busca binaria recursiva */
PONT buscaBinaria(TIPOCHAVE ch, PONT raiz) {
	if (raiz == NULL) return NULL;
	if (raiz->chave == ch) return raiz;
	if (raiz->chave<ch) 
		return buscaBinaria(ch,raiz->dir);
	return buscaBinaria(ch,raiz->esq);
}  

// Busca binária não recursiva devolvendo o nó pai
PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai) {
	PONT atual = raiz;
	*pai = NULL;
	while (atual) {
		if(atual->chave == ch)
			return(atual);
		*pai = atual;
		if(ch < atual->chave) atual = atual->esq;
		else atual = atual->dir;
	}
	return(NULL);
}

/* Auxilir da funcao excluirChave, procura a maior chave menor que a chave que serah excluida */
PONT maiorAEsquerda(PONT p, PONT *ant) {
  *ant = p;
  p = p->esq;
  while (p->dir) {
    *ant = p;
    p = p->dir;
  }
  return(p);
}

/* exclui a chave com valor igual a ch */
int excluirAVL(PONT* raiz, TIPOCHAVE ch, int* alterou) {
  PONT atual = *raiz;
  if (!atual) {
    *alterou = false;
    return false;
  }
  if (atual->chave == ch){
    PONT substituto, pai_substituto;
    if(!atual->esq || !atual->dir) { // tem zero ou um filho
      if(atual->esq) substituto = atual->esq;
      else substituto = atual->dir;
      *raiz = substituto;
      free(atual);
      *alterou = true;
      return true;
    }
    else {   // tem dois filhos
      substituto = maiorAEsquerda(atual,&pai_substituto);
      atual->chave = substituto->chave;
      ch = substituto->chave; // continua o codigo excluindo o substituto
    }
  }
  int res;
  if (ch > atual->chave) {
    res = excluirAVL(&(atual->dir), ch, alterou);
    printf("Excluir recursivo a direita: %i(%i)\n", atual->chave, atual->bal); 
    if (*alterou){
       switch (atual->bal){
          case 1: atual->bal = 0;
          return true;
          case 0: atual->bal = -1;
          *alterou = false;
          return true;
          case -1: *raiz = rotacaoL(atual);
          if (atual->bal != 0) *alterou = false;
          return true;
       }
    }
  } else {
    res = excluirAVL(&(atual->esq), ch, alterou);
    printf("Excluir recursivo a esquerda: %i(%i)\n", atual->chave, atual->bal); 
    if (*alterou){
       switch (atual->bal){
          case -1: atual->bal = 0;
          return true;
          case 0: atual->bal = 1;
          *alterou = false;
          return true;
          case 1: *raiz = rotacaoR(atual);
          if (atual->bal != 0) *alterou = false;
          return true;
       }
    }
  }
  return res;
}

/* funcao auxiliar na destruicao (liberacao da memoria) de uma arvore */
void destruirAux(PONT subRaiz) {
	if (subRaiz){
		destruirAux(subRaiz->esq);
		destruirAux(subRaiz->dir);
		free(subRaiz);
	}
}

/* libera toda memoria de uma arvore e coloca NULL no valor da raiz */
void destruirArvore(PONT * raiz) {
	destruirAux(*raiz);
	*raiz = NULL;
}

/* inicializa arvore: raiz=NULL */
void inicializar(PONT * raiz) {
	*raiz = NULL;
}

void travessiaAux(PONT p, int *niv, TIPOCHAVE ch, int *achou) {
	if(p) {
		(*niv)++;// *niv = *niv + 1;
		if(p->chave == ch) *achou = true;
		else {
			travessiaAux(p->esq, niv, ch, achou);
			if(!(*achou)) travessiaAux(p->dir, niv, ch, achou);
			if(!(*achou)) *niv = *niv - 1;
		}
	}
}

/* Retorna true e o nivel de uma chave (caso seja encontrada) e false caso contrario. */
int travessia(PONT p, int *niv, TIPOCHAVE ch) {
	*niv = 0;
	PONT temp = buscaBinaria(ch,p);
	if (temp){
		int achou = false;
		travessiaAux(p, niv, ch, &achou);
		return true;
	}
	else return false;
}

