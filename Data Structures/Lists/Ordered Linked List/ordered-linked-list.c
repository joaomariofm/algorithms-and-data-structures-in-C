#include <stdio.h>
#include <stdlib.h>
#include "ordered-linked-list.h"

void initialize(LIST* list) {   
	list->init = NULL;
}

int lenght(LIST* lista) {

	int lenght = 0;

	POINTER end = lista->init;

	while (end != NULL) {
		lenght++;
		end = end->next;
	}

	return lenght;
}

void show(LIST* lista) {

	POINTER end = lista->init;

	printf("Lista: \"");

	do {
		printf("%i, ", end->record.key);
		end = end->next;
	} while(end->next != NULL);

	printf("%i\"\n", end->record.key);
}

POINTER sequentialSearch(LIST* lista, KEY key) {

	POINTER element = lista->init;

	while (element != NULL) {
		if(element->record.key == key) return element;
		element = element->next;
	}

	return NULL;   
}

POINTER pop(LIST* lista, KEY key, POINTER* lastElement) {

	POINTER currentElement = lista->init;
	*lastElement = NULL;

	while((currentElement != NULL) && (currentElement->record.key < key)) {
		*lastElement = currentElement;
		currentElement = currentElement->next;
	}

	if((currentElement != NULL) && (currentElement->record.key == key)) return currentElement;

	return NULL;
}

int insertElement(LIST* lista, RECORD record) {

	KEY key = record.key;
	POINTER lastELement, element;

	element = pop(lista, key, &lastELement);
	
	if(element != NULL) return -1;
	
	element = (POINTER) malloc(sizeof(ELEMENT));
	element->record = record;

	if(lastELement == NULL) {
		element->next = lista->init;
		lista->init = element;
	} else {
		element->next = lastELement->next;
		lastELement->next = element;
	}

	return 0;
}

int removeElement(LIST* lista, KEY key) {

	POINTER ant,i;

	i = pop(lista, key, &ant);

	if(i == NULL) return -1;
	
	if(ant == NULL) lista->init = i->next;
	
	else ant->next = i->next;
	
	free(i);

	return 0;
}

void reset(LIST* lista) {
    
	POINTER end = lista->init;

	while (end != NULL) {

		POINTER apagar = end;
		end = end->next;
		free(apagar);
	}

	lista->init = NULL;
}

