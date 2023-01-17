# include "push_swap.h"

void free_stack(t_list **stackx)
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