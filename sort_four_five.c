# include "push_swap.h"

void    ft_sort_four_five(t_ilist **stacka, t_ilist **stackb)
{
    int median;
    t_ilist *last;

    if (ft_is_lst_sorted(stacka, stackb))
        return;
    median = ft_get_median(*stacka);
    while (last = ft_ilstlast(*stacka) <= median)
        ft_reverse_rotate(stacka, 'a');
    while (*stacka->content <= median)
        ft_push(stacka, stackb, 'b');
    while (*stacka->next->content <= median)
    {
        ft_swap(stacka, 'a');
        ft_push(stacka, stackb, 'b');
    }
}