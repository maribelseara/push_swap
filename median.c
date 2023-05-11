/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:18:30 by mseara            #+#    #+#             */
/*   Updated: 2023/05/11 15:15:30 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_lst_to_array(t_ilist *stackx, int items)
{
	int	*sorted;
	int	i;

	sorted = malloc(sizeof(int) * items);
	if (!sorted)
		return (0);
	i = 0;
	while (i < items)
	{
		sorted[i++] = stackx->content;
		stackx = stackx->next;
	}
	return (sorted);
}

static int	*ft_get_sorted_array(t_ilist *stackx, int items)
{
	int	*sorted;
	int	i;
	int	j;
	int	tmp;

	sorted = ft_lst_to_array(stackx, items);
	if (!sorted)
		return (NULL);
	i = 0;
	while (i < items - 1)
	{
		j = 1;
		while (j < items)
		{
			if (sorted[j - 1] > sorted[j])
			{
				tmp = sorted[j];
				sorted[j] = sorted[j - 1];
				sorted[j - 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (sorted);
}

int	ft_get_median(t_ilist *stackx)
{
	int	items;
	int	*sorted;
	int	median;

	items = ft_count_lst_items(stackx);
	sorted = ft_get_sorted_array(stackx, items);
	if (!sorted)
		return (0);
	if (ft_count_lst_items(stackx) % 2 == 0)
		median = sorted[(items - 1) / 2];
	else
		median = sorted[(items - 2) / 2];
	free(sorted);
	return (median);
}

int	ft_get_chunk(t_ilist **stacka, int items)
{
	int	chunk_max;
	int	*sorted;
	int	total_items;

	total_items = ft_count_lst_items(*stacka);
	sorted = ft_get_sorted_array(*stacka, total_items);
	if (!sorted)
		return (0);
	chunk_max = sorted[items - 1];
	free(sorted);
	return (chunk_max);
}

int	ft_get_middle(t_ilist **stacka, int position)
{
	int	*sorted;
	int	middle;
	int	total_items;

	total_items = ft_count_lst_items(*stacka);
	sorted = ft_get_sorted_array(*stacka, total_items);
	if (!sorted)
		return (0);
	middle = sorted[total_items - position];
	return (middle);
}