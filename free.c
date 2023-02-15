# include "push_swap.h"

void ft_free_stack(t_ilist **stackx)
{
	t_ilist *nextnode;

    if (stackx)
	{
		while (*stackx)
		{
			nextnode = (*stackx)->next;
            free(*stackx);
			*stackx = nextnode;
		}	
	}
	*stackx = NULL;
}

void    ft_exit(t_ilist *stacka, t_ilist *stackb)
{
    ft_free_stack(&stacka);
    ft_free_stack(&stackb);
    exit(-1);
}