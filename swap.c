# include "push_swap.h"

static void    ft_swap_movement (it_list **stackx)
{
    int tmp;

    if (ft_count_lst_items(*stackx) < 2)
        return;
    tmp = (*stackx)->content;
    (*stackx)->content = (*stackx)->next->content;
    (*stackx)->next->content = tmp;
}

void    ft_swap (it_list **stackx, char stack_identifier)
{
    ft_swap_movement(stackx);
    ft_putchar_fd('s', 1);
    ft_putchar_fd(stack_identifier, 1);
    ft_putchar_fd('\n', 1);
}

void    ft_ss (it_list **stacka, it_list **stackb)
{
    ft_swap_movement(stacka);
    ft_swap_movement(stackb);
    ft_putstr_fd("ss\n", 1);
}