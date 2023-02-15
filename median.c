# include "push_swap.h"

int *ft_lst_to_array(t_ilist stackx, int items)
{
    int *sorted;
    int i;

    sorted = malloc(sizeof(int) * items);
    i = 0;
    while (i < items)
    {
        sorted[i++]=stackx->content;
        stackx = stackx->next;
    }
}

int *ft_get_sorted_array (t_ilist stackx, int items)
{
    int *sorted;
    int i;
    int j;
    int tmp;

    sorted = ft_lst_to_array(stackx, items);
    i = 0;
    while (i < items - 1)
    {
        j = 1;
        while (j < items)
        {
            if (array[j - 1] > array[j])
            {
                tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1]=tmp;
            }
            j++;
        }
        i++;
    }
    return (sorted);
}

int ft_get_median(t_ilist stackx)
{
    int items;
    int *sorted;

    items = ft_count_lst_items(stackx);
    sorted = ft_get_sorted_array(stackx, items);
    median = sorted[items/2];
    return (median);
}