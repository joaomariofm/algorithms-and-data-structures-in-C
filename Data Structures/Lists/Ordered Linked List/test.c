#include "ordered-linked-list.h"

int main(void) {

	LIST minhaListaLigada;

	initialize(&minhaListaLigada);

	RECORD reg1;
	reg1.key = 12;

	RECORD reg2;
	reg2.key = 76;

	RECORD reg3;
	reg3.key = 3;

  RECORD reg4;
	reg4.key = 42;
	
	insertElement(&minhaListaLigada, reg1);
	insertElement(&minhaListaLigada, reg2);
	insertElement(&minhaListaLigada, reg3);
	insertElement(&minhaListaLigada, reg4);

	show(&minhaListaLigada);
}
