#include "push_swap.h"

static int check_array(int *array, int len)
{
    int i;
    int j;

    i=0;
    while (i < len)
    {
        j = 0;
        if (!(array[i] > INT_MIN && array[i] < INT_MAX))
        {
            printf("Elemento %d del array: %d", i, array[i]);
            return (0);
        }
        while (j < i)
        {
            if (array[j] == array[i])
                return (0);
            j++;
        }
        i++;
    }
    return(1);
}

static int *create_stackb(int  *array, int len)
{
    int *b;

    b = malloc(sizeof(int) * len + 1);
    if (!b)
        return(NULL);
    return (b);
}

void push_swap(int *array)
{
    int *stackb;
    int arraylen;

    arraylen=sizeof(array)/sizeof(array[0]);
    if ((!check_array(array, arraylen)) || (!(stackb = create_stackb(array, arraylen))))
        return(write(1, "Error", 5));
    
}