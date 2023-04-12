/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:07:50 by mseara            #+#    #+#             */
/*   Updated: 2023/03/10 15:07:58 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ilist	*ft_ilstnew(int content)
{
	t_ilist	*lst;

	lst = malloc(sizeof(t_ilist) * 1);
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

t_ilist	*ft_ilstlast(t_ilist *lst)
{
	t_ilist	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_ilstadd_back(t_ilist **lst, t_ilist *new)
{
	t_ilist	*last;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last = ft_ilstlast(*lst);
			last->next = new;
		}
	}
}

int	ft_count_lst_items(t_ilist *lst)
{
	int	items;

	items = 1;
	if (!lst)
		return (items);
	while (lst->next)
	{
		items++;
		lst = lst->next;
	}
	return (items);
}

int	ft_is_lst_sorted(t_ilist **stacka)
{
	t_ilist	*tmp;

	tmp = *stacka;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
