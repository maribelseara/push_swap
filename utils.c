#include "push_swap.h"

int array_len(int *array)
{
    int len;
    len = 0;
    while (array[len] != NULL)
        len++;
    return(len);
}

int *get_sorted(int *array)
{
    int *sorted;
    int len;

    len = array_len(array);
    sorted = malloc(sizeof(int) * len + 1);
}

int get_median(int *array)
{
    int len;
    int *sorted;

    sorted = get_sorted(array);
    len = array_len(sorted);
    if (len % 2 == 0)
        return(sorted[len/2]);
    else
        return(sorted[(len/2) + 1]);
}
