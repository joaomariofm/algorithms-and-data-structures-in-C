#include <stdlib.h>
#include "../../../data-structures/lists/double-linked/double-linked-list.h"

POINTER search(LIST *list, KEY key) {
  POINTER current_element = list->init; 

  while (current_element != NULL && current_element->record.key != key)
  {
    current_element = current_element->next;
  }

  return current_element;
}

