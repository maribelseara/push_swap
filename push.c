#include "push_swap.h"

static void    ft_push_movement(it_list **source, it_list **destination)
{
    it_list *tmp;
    it_list *newsource;

    if (!*source)
        return;
    newsource = (*source)->next;
    tmp = *source;
    tmp->next = *destination;
    *destination = tmp;
    *source= newsource;
}

void    ft_push(it_list **source, it_list **destination, char stackname)
{
    ft_push_movement(source, destination);
    ft_putchar_fd('p', 1);
    ft_putchar_fd(stackname, 1);
    ft_putchar_fd('\n', 1);
}