#include "./binary-search.h"

int binarySearch(int *array, int arraySize, int x)
{
  int low = 0;
  int high = arraySize - 1;

  while(low <= high)
  {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

