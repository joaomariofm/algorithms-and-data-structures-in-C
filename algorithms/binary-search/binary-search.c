#include "./binary-search.h"

int binarySearch(int *array, int n, int x)
{
  int low = 0;
  int high = n - 1;

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

