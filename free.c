# include "push_swap.h"

void ft_free_stack(t_list **stackx)
{
	t_list *nextnode;

    if (stackx)
	{
		while (*stackx)
		{
			nextnode = (*stackx)->next;
            free(stackx);
			*stackx = nextnode;
		}	
	}
	*stackx = NULL;
}

void    ft_exit(t_list *stacka, t_list *stackb)
{
    ft_free_stack(&stacka);
    ft_free_stack(&stackb);
    exit(-1);
}