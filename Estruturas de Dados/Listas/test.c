#include "Lista_Ligada.h"

int main(void) {

	LISTA minhaListaLigada;

	inicializarLista(&minhaListaLigada);

	REGISTRO reg1;
	reg1.chave = 12;

	REGISTRO reg2;
	reg2.chave = 76;

	REGISTRO reg3;
	reg3.chave = 3;
	
	inserirElemListaOrd(&minhaListaLigada, reg1);
	inserirElemListaOrd(&minhaListaLigada, reg2);
	inserirElemListaOrd(&minhaListaLigada, reg3);

	exibirLista(&minhaListaLigada);
}
