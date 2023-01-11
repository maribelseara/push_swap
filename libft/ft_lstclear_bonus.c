/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:54:53 by mseara            #+#    #+#             */
/*   Updated: 2022/09/30 16:50:45 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nextnode;

	if (lst)
	{
		while (*lst)
		{
			nextnode = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = nextnode;
		}	
	}
	*lst = NULL;
}
