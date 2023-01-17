# include "push_swap.h"

static int check_arguments(int ac, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        while (ft_isspace(argv[i][j]))
            j++;
        if (argv[i][j] == '-' || argv[i][j] == '+')
            j++;
        while (argv[i][j] != '\0')
        {
            if (!ft_isdigit(argv[i][j]))
                return (-1);
            j++;
        }
        i++;
    }
    return(0);
}

int main(int ac, char **argv)
{

    if (ac == 1 || check_arguments(ac, argv) == -1)
    {
        ft_putstr_fd("Error\n", 1);
        return(-1);
    }
    return(0);
}