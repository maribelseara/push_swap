/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:28:15 by mseara            #+#    #+#             */
/*   Updated: 2023/04/12 17:33:01 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_big_list(t_ilist **stacka, t_ilist **stackb, int num_chunks)
{
	int	items_chunk;
	int	chunk_max;
	int	i;
	int	j;
	
	i = 0;
	items_chunk = ft_count_lst_items(*stacka) / num_chunks;
	while (i < num_chunks)
	{
		chunk_max = ft_get_chunk(stacka, items_chunk);
		ft_divide_stacks(stacka, stackb, chunk_max, items_chunk);
		j = 0;
		while (j++ < items_chunk / 2)
			ft_rotate(stackb, 'b');
		i++;
	}
}
