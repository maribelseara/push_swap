/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:26:29 by mseara            #+#    #+#             */
/*   Updated: 2023/03/10 15:26:33 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_movement(t_ilist **stackx)
{
	t_ilist	*tmp;
	int		last;

	tmp = *stackx;
	last = tmp->content;
	if (!tmp || !tmp->next)
		return ;
	while (tmp->next != NULL)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next;
	}
	tmp->content = last;
}

void	ft_rotate(t_ilist **stackx, char stackname)
{
	ft_rotate_movement(stackx);
	ft_putchar_fd('r', 1);
	ft_putchar_fd(stackname, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_rr(t_ilist **stacka, t_ilist **stackb)
{
	ft_rotate_movement(stacka);
	ft_rotate_movement(stackb);
	ft_putstr_fd("rr\n", 1);
}
