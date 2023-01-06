#include "push_swap.h"

void    swap(int *array)
{
    int tmp;

    tmp = array[0];
    array[0]=array[1];
    array[1]=tmp;
}

void    push(int *stackorig, int *stackdest)
{
    int tmp;
    int len;
    int i;

    i=0;
    if (stackorig[0] = NULL)
        return(NULL);
    tmp = stackorig[0];
    while(stackorig[i]!=NULL)
    {
        stackorig[i]=stackorig[i+1];
        i++;
    }
    len = array_len(stackdest);
    while(len > 0)
    {
        stackdest[len] = stackdest[len - 1];
        len--;
    }
    stackdest[0]=tmp;
}

void    rotate(int *array)
{
    int tmp;
    int i;

    i = 0;
    tmp = array[0];
    while (array[i]=!NULL)
    {
        array[i] = array [i + 1];
        i++;
    }
    array [i - 1] = tmp;
}

void    reverse_rotate(int  *array)
{
    int tmp;
    int i;

    i = array_len(array);
    tmp = array [i - 1];
    i = 1;
    while (array[i] != NULL)
    {
        array[i]=array[i - 1];
        i++;
    }
    array[0] = tmp;
}