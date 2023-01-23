# include "push_swap.h"

void ft_free_stack(it_list **stackx)
{
	it_list *nextnode;

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

void    ft_exit(it_list *stacka, it_list *stackb)
{
    ft_free_stack(&stacka);
    ft_free_stack(&stackb);
    exit(-1);
}