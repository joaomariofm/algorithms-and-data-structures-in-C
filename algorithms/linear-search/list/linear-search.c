#include <stdlib.h>
#include "./linear-search.h"

POINTER linearSearch(LIST *list, KEY key) {
  POINTER current_element = list->init; 

  while (current_element != NULL && current_element->record.key != key)
  {
    current_element = current_element->next;
  }

  return current_element;
}

