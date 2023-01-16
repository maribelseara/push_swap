# include "push_swap.h"

void free_stack(t_stack **stackx)
{
    t_stack *nextnode;

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