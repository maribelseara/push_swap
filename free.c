/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:06:48 by mseara            #+#    #+#             */
/*   Updated: 2023/04/19 11:33:51 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_args(int numargs, char **args)
{
	int	i;

	i = 0;
	while (i < numargs)
		free(args[i++]);
	free(args);
}

void	ft_free_stack(t_ilist **stackx)
{
	t_ilist	*nextnode;

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

void	ft_exit(t_ilist *stacka, t_ilist *stackb)
{
	ft_free_stack(&stacka);
	ft_free_stack(&stackb);
	exit(0);
}
