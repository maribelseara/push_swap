/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:30:53 by mseara            #+#    #+#             */
/*   Updated: 2022/09/30 13:49:14 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*last;
	int		len;

	if (!lst)
		return (0);
	len = 0;
	last = lst;
	while (last)
	{
		len++;
		last = last->next;
	}
	return (len);
}
