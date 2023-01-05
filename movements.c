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
    while(stackdest[i] != NULL)
        i++;
    while(i > 0)
    {
        stackdest[i] = stackdest[i - 1];
        i--;
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

    i=0;
    while (array[i] != NULL)
        i++;
    tmp = array [i - 1];
    i = 1;
    while (array[i] != NULL)
    {
        array[i]=array[i - 1];
        i++;
    }
    array[0] = tmp;
}