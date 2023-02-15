#include "push_swap.h"

static void    ft_push_movement(t_ilist **source, t_ilist **destination)
{
    t_ilist *tmp;
    t_ilist *newsource;

    if (!*source)
        return;
    newsource = (*source)->next;
    tmp = *source;
    tmp->next = *destination;
    *destination = tmp;
    *source= newsource;
}

void    ft_push(t_ilist **source, t_ilist **destination, char stackname)
{
    ft_push_movement(source, destination);
    ft_putchar_fd('p', 1);
    ft_putchar_fd(stackname, 1);
    ft_putchar_fd('\n', 1);
}