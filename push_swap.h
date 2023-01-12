#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft.h"

typedef struct stack_list
{
	int			    value;
	struct stack_list	*next;
}	t_stack;


void free_stack(t_stack stackx);

#endif