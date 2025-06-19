#include "./binary-search.h"

int binarySearch(int *V, int N, int elem)
{
    int beginning = 0;
    int end = N - 1;
    int middle;

    while(beginning <= end)
    {
        middle = (beginning + end)/2;

        if(elem < V[middle])
            end = middle - 1;
        else   
            if(elem > V[middle])
                beginning = middle + 1;
            else    
                return middle;
    }

    return -1;
}

