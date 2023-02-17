# include "push_swap.h"

void    ft_sort_four_five(t_ilist **stacka, t_ilist **stackb)
{
    int median;
    int to_pass;
    int position;
    t_ilist *tmp;

    to_pass = ft_count_lst_items(*stacka) / 2;
    if (ft_is_lst_sorted(stacka, stackb))
        return;
    median = ft_get_median(*stacka);
    position = 1;
    tmp = *stacka;
    while (to_pass > 0)
    {
        if ((tmp)->content <= median)
        {
            if (position <= ft_count_lst_items(*stacka)/ 2)
            {
                while (position > 1)
                {
                    ft_rotate(stacka, 'a');
                    position--;
                }
            }
            else
            {
                while (position < ft_count_lst_items(*stacka))
                {
                    ft_reverse_rotate(stacka, 'a');
                    position++;
                }
            }
            ft_push(stacka, stackb, 'b');
            to_pass--;
            tmp= (*stacka);
            position=1;
        }
        else
        {
            tmp = tmp->next;
            position++;
        }
    }
}