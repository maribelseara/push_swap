# include "push_swap.h"

static int check_arguments(int ac, char **argv)
{
    int i;
    int j:

    i = 1;
    while (i < ac)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            if (!(argv[i][j] >= '0' && argv[i][j] <= '9' || argv[i][j] == '+' ||
             argv[i][j] == '-' || ft_isspace(argv[i][j])))
                return (-1);
            j++;
        }
        i++;
    }
    return(0);
}

static t_stack create_stacka(int ac, char **argv)
{
    t_stack *stacka;
    int     num;

    stacka=malloc(sizeof(t_stack) * (ac - 1));
    if(!stacka)
        return (NULL);
    while (i < ac)
    {
        num = convert_to_int(argv[i]);
        if(!num)
        {
            ft_free_stack(stacka);
            ft_putstr("Error\n");
            exit(-1);
        }
        
        i++;
    }
}

int main(int ac, char **argv)
{
    t_stack *stacka;
    if (ac == 1 || check_arguments(ac, argv) == -1)
    {
        ft_putstr("Error\n");
        return(-1);
    }
    stacka = create_stacka(ac, argv);
    return(0);
}