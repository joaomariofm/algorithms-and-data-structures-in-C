#include "./linear-search.h"

int linearSearch(int *array, int arraySize, int x)
{
  for(int i = 0; i<arraySize; i++)
    if(array[i] == x)
      return i;

  return -1;
}

