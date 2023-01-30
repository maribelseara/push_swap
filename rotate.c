#include "push_swap.h"

void    ft_rotate_movement(it_list **stackx)
{
    it_list *tmp;
    int last;

    tmp= *stackx;
    last = tmp->content;
    if (!tmp || !tmp->next)
        return;
    while(tmp->next != NULL)
    {
        tmp->content = tmp->next->content;
        tmp = tmp->next;
    }
    tmp->content = last;
}

void    ft_rotate(it_list **stackx, char stackname)
{
    ft_rotate_movement(stackx);
    ft_putchar_fd('r', 1);
    ft_putchar_fd(stackname, 1);
    ft_putchar_fd('\n', 1);
}

void    ft_rr(it_list **stacka, it_list **stackb)
{
    ft_rotate_movement(stacka);
    ft_rotate_movement(stackb);
    ft_putstr_fd("rr\n", 1);
}