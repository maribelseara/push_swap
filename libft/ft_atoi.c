/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:59:53 by mseara            #+#    #+#             */
/*   Updated: 2023/01/12 15:37:35 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '	')
		return (1);
	else if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

static int	get_num(const char *str, int i)
{
	int	num;

	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + (str[i] - '0');
		else
			break ;
		i++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	is_negative;

	i = 0;
	is_negative = 0;
	while (ft_isspace(str[i]) == 1)
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negative++;
		i++;
	}
	num = get_num(str, i);
	if (is_negative % 2 == 0)
		return (num);
	else
		return (num * (-1));
}
