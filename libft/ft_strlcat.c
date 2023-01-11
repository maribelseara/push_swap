/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:00:11 by mseara            #+#    #+#             */
/*   Updated: 2022/09/20 12:00:45 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(dest);
	if (size > len)
	{	
		while (src[i] != '\0' && i < (size - len - 1))
		{	
			dest[len + i] = src[i];
			i++;
		}
		dest[len + i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	if (size <= len)
		return (size + i);
	else
		return (len + i);
}
