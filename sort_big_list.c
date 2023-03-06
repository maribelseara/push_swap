# include "push_swap.h"

void ft_sort_big_list(t_ilist **stacka, t_ilist **stackb, int num_chunks)
{
    int items_chunk;
    int chunk_max;
    int i;
    //borrar
    (void)stackb;
    i = 0;
    items_chunk = ft_count_lst_items(*stacka) / num_chunks;
   while (i < num_chunks)
   {
        chunk_max = ft_get_chunk(stacka, items_chunk);
        ft_divide_stacks(stacka, stackb, chunk_max, items_chunk);
        i++;
   }
}