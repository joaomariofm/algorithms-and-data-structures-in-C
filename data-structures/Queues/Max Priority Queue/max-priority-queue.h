#include <stdio.h>
#include <stdlib.h>
#include "../..//Heaps/Max Heap/max-heap.h"

int HeapMax(int* A);

int HeapExtractMax(HEAP* h);

void HeapIncreaseKey(HEAP* h, int i, int chave);

void MaxHeapInsert(HEAP* h, int chave);
