/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:43:26 by mseara            #+#    #+#             */
/*   Updated: 2022/10/01 12:09:46 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_all(char **array, int items)
{
	int	j;

	j = 0;
	while (j < items)
	{
		free(array[j]);
		j++;
	}
	free(array);
	return (NULL);
}

static int	ft_items(char const *s, char c)
{
	int	i;
	int	items;

	i = 0;
	items = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			items++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (items);
}

static char	**fill_array(char **array, const char *s, char c)
{
	int	start;
	int	len;
	int	i;
	int	items;

	start = 0;
	len = 0;
	i = 0;
	items = ft_items(s, c);
	while (i < items)
	{
		while (*s && *s == c)
			s++;
		while (s[len] && s[len] != c)
			len++;
		array[i] = ft_substr(s, 0, len);
		if (!array[i])
			return (free_all(array, i));
		s = s + len;
		len = 0;
		i++;
	}
	array[i] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (ft_items(s, c) + 1));
	if (!array)
		return (NULL);
	array = fill_array(array, s, c);
	return (array);
}
