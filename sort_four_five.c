# include "push_swap.h"

void    ft_move_lst_element(t_ilist **stacka, int *position)
{
   if (*position <= ft_count_lst_items(*stacka)/ 2)
    {
        while (*position-- > 1)
        ft_rotate(stacka, 'a');
    }
    else
    {
        while (*position++ < ft_count_lst_items(*stacka))
        ft_reverse_rotate(stacka, 'a');
    }
}

void    ft_divide_stacks(t_ilist **stacka, t_ilist **stackb, int median)
{
    t_ilist *tmp;
    int position;
    int to_pass;

    position = 1;
    tmp = *stacka;
    to_pass = ft_count_lst_items(*stacka) / 2;
    while (to_pass > 0)
    {
        if ((tmp)->content <= median)
        {
            ft_move_lst_element(stacka, &position);
            ft_push(stacka, stackb, 'b');
            to_pass--;
            tmp= (*stacka);
            position = 1;
        }
        else
        {
            tmp = tmp->next;
            position++;
        }
    }
}

void    ft_sort_four_five(t_ilist **stacka, t_ilist **stackb)
{
    int median;
    
    if (ft_is_lst_sorted(stacka, stackb))
        return;
    median = ft_get_median(*stacka);
    ft_divide_stacks(stacka, stackb, median);
    if (ft_count_lst_items(*stacka) == 3)
        ft_sort_three(stacka, stackb);
    else
        ft_sort_two(stacka, stackb);
    if ((*stackb)->content < (*stackb)->next->content)
        ft_swap(stackb, 'b');
    ft_push(stackb, stacka, 'a');
    ft_push(stackb, stacka, 'a');
}