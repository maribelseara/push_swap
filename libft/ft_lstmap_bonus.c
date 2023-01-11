/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:04:30 by mseara            #+#    #+#             */
/*   Updated: 2022/09/30 19:23:34 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*first;
	void	*ptr;

	if (!lst || !f)
		return (NULL);
	first = 0;
	while (lst)
	{
		ptr = (f)(lst->content);
		new = ft_lstnew(ptr);
		if (!new)
		{
			ft_lstclear(&first, del);
			free(ptr);
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
