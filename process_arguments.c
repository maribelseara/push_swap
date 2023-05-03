#include "push_swap.h"

static char    **ft_get_args(int ac, char **argv, int *numargs)
{
    char **args;

    if (ac == 2)
	{
		*numargs = ft_items(argv[1], ' ');
		if (*numargs > 0)
			args = ft_split(argv[1], ' ');
		else
		{
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
	}
    else
	{
		*numargs = ac - 1;
		args = ft_copy_arguments(ac, argv);
		if (!args)
			return (NULL);
	}
    return args;
}

t_ilist	*ft_process_arguments(int ac, char **argv)
{
    t_ilist *stacka;
    char	**args;
	int		numargs;

    args=ft_get_args(ac, argv, &numargs);
    if (!args)
        return (NULL);
    if (check_arguments(numargs, args) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
    stacka = ft_create_stacka(numargs, args);
	ft_free_args(numargs, args);
	ft_check_duplicates(stacka);
	if (numargs == 1)
		ft_exit(stacka, NULL);
    return (stacka);
}