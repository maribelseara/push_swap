/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:24:22 by mseara            #+#    #+#             */
/*   Updated: 2023/05/17 12:26:36 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate_movement(t_ilist **stackx)
{
	t_ilist	*tmp;
	int		origin;
	int		dest;

	tmp = *stackx;
	if (!tmp || !tmp->next)
		return ;
	origin = tmp->content;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		dest = tmp->content;
		tmp->content = origin;
		origin = dest;
	}
	(*stackx)->content = origin;
}

void	ft_reverse_rotate(t_ilist **stackx, char stackname)
{
	ft_reverse_rotate_movement(stackx);
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(stackname, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_rrr(t_ilist **stacka, t_ilist **stackb)
{
	ft_reverse_rotate_movement(stacka);
	ft_reverse_rotate_movement(stackb);
	ft_putstr_fd("rrr\n", 1);
}
