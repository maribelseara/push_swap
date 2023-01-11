/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:04:04 by mseara            #+#    #+#             */
/*   Updated: 2022/09/21 12:12:34 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*st2;
	char	*st1;
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	st1 = (char *)s1;
	st2 = (char *)malloc(sizeof(char) * len + 1);
	if (!st2)
		return (NULL);
	while (st1[i])
	{
		st2[i] = st1[i];
		i++;
	}
	st2[i] = 0;
	return (st2);
}
