/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:39:58 by mseara            #+#    #+#             */
/*   Updated: 2022/09/20 17:44:46 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*sc1;
	unsigned char	*sc2;

	i = 0;
	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (sc1[i] != '\0' && sc2[i] != '\0' && (i < n - 1)
		&& (sc1[i] == sc2[i]))
	{
		i++;
	}
	return (sc1[i] - sc2[i]);
}
