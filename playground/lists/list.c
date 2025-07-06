#include <stdlib.h>
#include <stdio.h>
#include "../../data-structures/lists/double-linked/double-linked-list.h"

ELEMENT createElement(KEY key)
{
  RECORD new_record;

  new_record.key = key;

  ELEMENT new_element;

  new_element.next = NULL;
  new_element.prev = NULL;
  new_element.record = new_record;

  return new_element;
}

void show (LIST *list)
{
  POINTER currenct_reference = list->init; 

  printf("My list: ");

  do
  {
    printf("%i ", currenct_reference->record.key);
    currenct_reference = currenct_reference->next;
  }
  while (currenct_reference != NULL);

  printf("\n");
}

int main (void)
{
  LIST list;

  init(&list);

  ELEMENT element_1 = createElement(10);
  ELEMENT element_2 = createElement(4);
  ELEMENT element_3 = createElement(1);
  ELEMENT element_4 = createElement(8);
  ELEMENT element_5 = createElement(3);
  ELEMENT element_6 = createElement(5);
  ELEMENT element_7 = createElement(6);
  ELEMENT element_8 = createElement(7);
  ELEMENT element_9 = createElement(9);
  ELEMENT element_10 = createElement(2);

  insert(&list, &element_1);
  insert(&list, &element_2);
  insert(&list, &element_3);
  insert(&list, &element_4);
  insert(&list, &element_5);
  insert(&list, &element_6);
  insert(&list, &element_7);
  insert(&list, &element_8);
  insert(&list, &element_9);
  insert(&list, &element_10);

  show(&list);

  return 0;
}
