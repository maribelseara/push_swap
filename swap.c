/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:35:34 by mseara            #+#    #+#             */
/*   Updated: 2023/03/10 15:35:38 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_movement(t_ilist **stackx)
{
	int	tmp;

	if (ft_count_lst_items(*stackx) < 2)
		return ;
	tmp = (*stackx)->content;
	(*stackx)->content = (*stackx)->next->content;
	(*stackx)->next->content = tmp;
}

void	ft_swap(t_ilist **stackx, char stackname)
{
	ft_swap_movement(stackx);
	ft_putchar_fd('s', 1);
	ft_putchar_fd(stackname, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_ss(t_ilist **stacka, t_ilist **stackb)
{
	ft_swap_movement(stacka);
	ft_swap_movement(stackb);
	ft_putstr_fd("ss\n", 1);
}
