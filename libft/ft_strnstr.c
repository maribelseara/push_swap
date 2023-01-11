/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:15:20 by mseara            #+#    #+#             */
/*   Updated: 2022/09/26 13:04:41 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	s_match(const char *hay, const char *needle, size_t i, size_t len)
{
	size_t	j;
	int		matches;

	j = 0;
	matches = 1;
	while (needle[j] != '\0')
	{
		if (hay[i] != needle[j] || i >= len)
			return (0);
		j++;
		i++;
	}
	return (matches);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		match;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			match = s_match(haystack, needle, i, len);
			if (match == 1)
				return (&((char *)haystack)[i]);
		}
		i++;
	}	
	return (0);
}
