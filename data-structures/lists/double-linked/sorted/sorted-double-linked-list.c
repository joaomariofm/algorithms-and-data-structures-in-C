#include <stdio.h>
#include <stdlib.h>
#include "../double-linked-list.h"
#include "../../../../algorithms//linear-search/list/linear-search.h"

// Query operations

POINTER prev(LIST *list, POINTER element)
{
  POINTER found_element = linearSearch(list, element->record.key);

  return found_element->prev;
}

POINTER next(LIST *list, POINTER element)
{
  POINTER found_element = linearSearch(list, element->record.key);

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
  if (list->init == NULL)
  {
    list->init = element;
    element->prev = NULL;
    element->next = NULL; 
    return;
  }

  if (element->record.key < list->init->record.key)
  {
    element->prev = NULL;
    element->next = list->init;
    list->init->prev = element;
    list->init = element;
    return;
  }

  POINTER current_element = list->init;

  while
  (
    current_element->next != NULL &&
    current_element->record.key < element->record.key
  )
  {
    current_element = current_element->next;
  }

  if
  (
   current_element->next == NULL &&
   current_element->record.key < element->record.key
  )
  {
    current_element->next = element;
    element->prev = current_element;
    element->next = NULL;
    return;
  }

  element->next = current_element;
  element->prev = current_element->prev;
  current_element->prev->next = element;
  current_element->prev = element;
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

