/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:39:45 by mseara            #+#    #+#             */
/*   Updated: 2023/05/03 12:50:53 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_copy_arguments(int ac, char **argv)
{
	int		i;
	char	**args;

	i = 0;
	args = malloc(sizeof(char *) * (ac - 1));
	if (!args)
		return (NULL);
	while (i < ac - 1)
	{
		args[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	return (args);
}

int	check_arguments(int numargs, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < numargs)
	{
		j = 0;
		while (ft_isspace(args[i][j]))
			j++;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		if (args[i][j] == '\0')
			return (-1);
		while (args[i][j] != '\0')
		{
			if (!ft_isdigit(args[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

t_ilist	*ft_create_stacka(int numargs, char **args)
{
	t_ilist			*stacka;
	t_ilist			*node;
	long long int	num;
	int				i;

	i = 0;
	stacka = NULL;
	while (i < numargs)
	{
		num = ft_atol(args[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			ft_exit(stacka, NULL);
		}
		node = ft_ilstnew(num);
		if (!node)
			ft_exit(stacka, NULL);
		ft_ilstadd_back(&stacka, node);
		i++;
	}
	return (stacka);
}

void	ft_check_duplicates(t_ilist *stacka)
{
	t_ilist	*compare;

	while (stacka)
	{
		compare = stacka->next;
		while (compare)
		{
			if (compare->content == stacka->content)
			{
				ft_putstr_fd("Error\n", 2);
				ft_exit(stacka, NULL);
			}
			compare = compare->next;
		}
		stacka = stacka->next;
	}
}

/*int	main(int ac, char **argv)
{
	t_ilist	*stacka;
	t_ilist	*stackb;
	char	**args;
	int		numargs;

	if (ac < 2)
		return (0);
	
	if (ac == 2)
	{
		numargs = ft_items(argv[1], ' ');
		if (numargs > 0)
			args = ft_split(argv[1], ' ');
		else
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
	}
	else
	{
		numargs = ac - 1;
		args = ft_copy_arguments(ac, argv);
		if (!args)
			return (0);
	}
	if (check_arguments(numargs, args) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	stacka = ft_create_stacka(numargs, args);
	ft_free_args(numargs, args);
	ft_check_duplicates(stacka);
	stackb = NULL;
	if (numargs == 1)
		ft_exit(stacka, stackb);
	ft_filter_elements_number(&stacka, &stackb);
	ft_exit(stacka, stackb);
	return (0);
}*/

int	main(int ac, char **argv)
{
	t_ilist	*stacka;
	t_ilist	*stackb;

	if (ac < 2)
		return (0);
	stackb = NULL;
	stacka = ft_process_arguments(ac, argv);
	if (stacka)
		ft_filter_elements_number(&stacka, &stackb);
	ft_exit(stacka, stackb);
	return (0);
}
