/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:05:37 by mseara            #+#    #+#             */
/*   Updated: 2023/03/10 15:05:42 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_ilist **stacka)
{
	if (ft_is_lst_sorted(stacka) == 0)
		ft_swap(stacka, 'a');
}

static void	ft_sort_three_else(t_ilist **stacka)
{
	if ((*stacka)->content < (*stacka)->next->next->content)
		ft_swap(stacka, 'a');
	else
	{
		if ((*stacka)->next->content < (*stacka)->next->next->content)
			ft_rotate(stacka, 'a');
		else
		{
			ft_swap(stacka, 'a');
			ft_reverse_rotate(stacka, 'a');
		}
	}
}

void	ft_sort_three(t_ilist **stacka)
{
	if (ft_is_lst_sorted(stacka))
		return ;
	if ((*stacka)->content < (*stacka)->next->content)
	{
		if ((*stacka)->content < (*stacka)->next->next->content)
		{
			ft_swap(stacka, 'a');
			ft_rotate(stacka, 'a');
		}
		else
			ft_reverse_rotate(stacka, 'a');
	}
	else
		ft_sort_three_else(stacka);
}

void	ft_filter_elements_number(t_ilist **stacka, t_ilist **stackb)
{
	int	elements;

	elements = ft_count_lst_items(*stacka);
	if (elements == 2)
		ft_sort_two(stacka);
	else if (elements == 3)
		ft_sort_three(stacka);
	else if (elements <= 5)
		ft_sort_four_five(stacka, stackb);
	else if (elements <= 100)
		ft_sort_big_list(stacka, stackb, 5);
}
