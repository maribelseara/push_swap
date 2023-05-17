/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:28:15 by mseara            #+#    #+#             */
/*   Updated: 2023/05/17 12:29:42 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_max(t_ilist **stackx)
{
	int		max;
	t_ilist	*tmp;

	tmp = *stackx;
	max = tmp->content;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->content > max)
			max = tmp->content;
	}
	return (max);
}

static int	ft_get_second_max(t_ilist **stackx, int max)
{
	int		second_max;
	t_ilist	*tmp;

	tmp = *stackx;
	if (tmp->content != max)
		second_max = tmp->content;
	else
		second_max = tmp->next->content;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (second_max < tmp->content && tmp->content != max)
			second_max = tmp->content;
	}
	return (second_max);
}

static void	ft_return_maxs(t_ilist **stacka, t_ilist **stackb,
int max, int second_max)
{
	t_ilist	*tmp;
	int		position;
	int		passed;

	position = 1;
	passed = 0;
	tmp = *stackb;
	while (tmp)
	{
		if (tmp->content == max || tmp->content == second_max)
		{
			ft_return_lst_element(stackb, position);
			ft_push(stackb, stacka, 'a');
			passed++;
			if (passed == 2)
				break ;
			tmp = *stackb;
			position = 1;
		}
		else
		{
			tmp = tmp->next;
			position++;
		}
	}
}

static void	ft_return_items_to_stacka(t_ilist **stacka, t_ilist **stackb)
{
	int	max;
	int	second_max;

	while (ft_count_lst_items(*stackb) > 0)
	{
		max = ft_get_max(stackb);
		if (ft_count_lst_items(*stackb) == 1)
		{
			ft_push(stackb, stacka, 'a');
			if ((*stacka)->content > (*stacka)->next->content)
				ft_swap(stacka, 'a');
			break ;
		}
		second_max = ft_get_second_max(stackb, max);
		ft_return_maxs(stacka, stackb, max, second_max);
		if (ft_count_lst_items(*stacka) >= 2)
		{
			if ((*stacka)->content > (*stacka)->next->content)
				ft_swap(stacka, 'a');
		}
	}
}

void	ft_sort_big_list(t_ilist **stacka, t_ilist **stackb, int num_chunks)
{
	int	items_chunk;
	int	chunk_max;
	int	i;

	if (ft_is_lst_sorted(stacka))
		return ;
	i = 0;
	items_chunk = ft_count_lst_items(*stacka) / num_chunks;
	while (i <= num_chunks)
	{
		if (i == num_chunks)
			items_chunk = ft_count_lst_items(*stacka);
		chunk_max = ft_get_chunk(stacka, items_chunk);
		ft_divide_stacks(stacka, stackb, chunk_max, items_chunk);
		i++;
	}
	ft_return_items_to_stacka(stacka, stackb);
}
