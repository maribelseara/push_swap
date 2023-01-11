/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:56:01 by mseara            #+#    #+#             */
/*   Updated: 2022/09/26 10:03:52 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	len;
	int		i;

	if (s)
	{
		i = 0;
		len = ft_strlen(s);
		while ((size_t)i < len)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
