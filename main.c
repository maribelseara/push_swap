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

static t_ilist  *ft_create_stacka(int ac, char **argv)
{
    t_ilist  *stacka;
    t_ilist  *node;
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

static void    ft_check_duplicates(t_ilist *stacka)
{
    t_ilist *compare;
    while(stacka)
    {
        compare = stacka->next;
        while (compare)
        {
            if (compare->content == stacka->content)
            {
                ft_putstr_fd("Error\n", 1);
                ft_exit(stacka, NULL);
            }
            compare = compare->next;
        }
        stacka = stacka->next;
    }
}

int main(int ac, char **argv)
{
    t_ilist *stacka;
    t_ilist *stackb;

    if (ac < 2)
        return(0);
    if (check_arguments(ac, argv) == -1)
    {
        ft_putstr_fd("Error\n", 1);
        return(-1);
    }
    if (ac == 2)
        return (0);
    stacka = ft_create_stacka(ac, argv);
    ft_check_duplicates(stacka);
    stackb = NULL;
    //ft_filter_elements_number(&stacka, &stackb);
    //ft_printlst(stacka);
    printf("Mediana del stack: %d\n", ft_get_median(stacka));
    ft_exit(stacka, stackb);
    return(0); 
}