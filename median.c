# include "push_swap.h"

static int *ft_lst_to_array(t_ilist *stackx, int items)
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
    return (sorted);
}

static int *ft_get_sorted_array (t_ilist *stackx, int items)
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
            if (sorted[j - 1] > sorted[j])
            {
                tmp = sorted[j];
                sorted[j] = sorted[j - 1];
                sorted[j - 1]=tmp;
            }
            j++;
        }
        i++;
    }
    return (sorted);
}

int ft_get_median(t_ilist *stackx)
{
    int items;
    int *sorted;
    int median;

    items = ft_count_lst_items(stackx);
    sorted = ft_get_sorted_array(stackx, items);
    if (ft_count_lst_items(stackx) % 2 == 0)
        median = sorted[(items-1)/2];
    else
        median = sorted[(items-2)/2];
    return (median);
}