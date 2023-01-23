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

it_list  *ft_create_stacka(int ac, char **argv)
{
    it_list  *stacka;
    it_list  *node;
    long long int num;
    int i;
    
    i = 1;
    stacka = NULL;
    while(i < ac)
    {
        num = ft_atol(argv[i]);
        if (num > INT_MAX || num < INT_MIN)
        {
            ft_putstr_fd("Error\n", 1);
            ft_exit(stacka, NULL);
        }
        node = ft_ilstnew(num);
        if(!node)
            ft_exit(stacka, NULL);
        ft_ilstadd_back(&stacka, node);
        i++;
    }
    return(stacka);
}

int main(int ac, char **argv)
{
    it_list  *stacka;

    if (check_arguments(ac, argv) == -1)
    {
        ft_putstr_fd("Error\n", 1);
        return(-1);
    }
    stacka = ft_create_stacka(ac, argv);
    ft_printlst(stacka);
    return(0);
}