/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 utils.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mseara <mseara@student.42.fr>				+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2023/03/10 14:51:20 by mseara			   #+#	  #+#			  */
/*	 Updated: 2023/03/10 14:51:22 by mseara			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atol(const char *str)
{
	long long int	num;
	int				is_negative;

	is_negative = 1;
	num = 0;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	num = num * is_negative;
	return (num);
}

void	ft_return_lst_element(t_ilist **stackb, int position)
{
	if (position <= ft_count_lst_items(*stackb) / 2)
	{
		while (position-- > 1)
			ft_rotate(stackb, 'b');
	}
	else
	{
		while (position <= ft_count_lst_items(*stackb))
		{
			ft_reverse_rotate(stackb, 'b');
			position++;
		}
	}
}