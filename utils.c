#include "push_swap.h"

int *get_sorted(int *array, int len)
{
    int *sorted;
    int i;
    int tmp;

    i = 0;
    sorted = malloc(sizeof(int) * len + 1);
    while (i < len)
        sorted[i++]=array[i++]
    while (i < len)
    {
        if (sorted[i] > sorted[i + 1])
        {
            tmp = sorted[i];
            sorted[i] = sorted[i + 1];
            sorted[i + 1] = tmp;
            i = 0;
        }
        else
            i++;
    }
}

int get_median(int *array, int len)
{
    int *sorted;

    sorted = get_sorted(array);
    if (len % 2 == 0)
        return(sorted[len/2]);
    else
        return(sorted[(len/2) + 1]);
}
