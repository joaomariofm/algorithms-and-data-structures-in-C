#include <stdio.h>
#include <stdlib.h>
#include "./double-linked-list.h"

// Query operations

POINTER prev(LIST *list, POINTER element)
{
  POINTER found_element = search(list, element->record.key);

  return found_element->prev;
}

POINTER next(LIST *list, POINTER element)
{
  POINTER found_element = search(list, element->record.key);

  return found_element->next;
}

// Modifying operations

void init(LIST* list)
{
	list->init = NULL;
}

void reset(LIST* lista)
{
	POINTER element = lista->init;

	while (element != NULL)
  {
		POINTER trash = element;
		element = element->next;
		free(trash);
	}

	lista->init = NULL;
}

void insert(LIST *list, POINTER element)
{
  element->next = list->init;

  if (list->init != NULL)
  {
    list->init->prev = element;
  }

  list->init = element;
  element->prev = NULL;
}

void discard(LIST *list, POINTER element)
{
  POINTER trash = element;

  if (element->prev != NULL) 
  {
    element->prev->next = element->next;
  }
  else
  {
    list->init = element->next;
  }

  if (element->next != NULL)
  {
    element->next->prev = element->prev;
  }

  free(trash);
}

