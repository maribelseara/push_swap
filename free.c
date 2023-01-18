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