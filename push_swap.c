#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

static int check_array(int *array)
{
    int i;
    int j;

    i=0;
    while (array[i] != NULL)
    {
        j = 0;
        if (!(array[i] > INT_MIN && array[i] < INT_MAX))
            return (0);
        while (j < i)
        {
            if (array[j] == array[i])
                return (0);
            j++;
        }
    }
    return(1);
}

static int *create_stackb(int  *array)
{
    int *b;
    int len;

    len = 0;
    while(array[len] != NULL)
        len++;
    b = malloc(sizeof(int) * len + 1);
    if (!b)
        return(NULL);
    return (b);
}

void push_swap(int *array)
{
    int *stackb;
    if ((!check_array(array)) || (!(b = create_stackb(array))))
        return(write(1, "Error", 5));
    
}