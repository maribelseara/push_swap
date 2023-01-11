# include "push_swap.h"

int check_arguments(int ac, char **argv)
{
    int i;

    i = 1;
    while (i < ac)
    {

    }
    return(0);
}

int main(int ac, char **argv)
{

    if (ac == 1 || check_arguments(ac, argv) == -1)
    {
        ft_putstr("Error\n");
        return(-1);
    }
    return(0);
}