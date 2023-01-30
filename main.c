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

static it_list  *ft_create_stacka(int ac, char **argv)
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

static void    ft_check_duplicates(it_list *stacka)
{
    it_list *compare;
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
    it_list *stacka;
    it_list *stackb;

    if (check_arguments(ac, argv) == -1)
    {
        ft_putstr_fd("Error\n", 1);
        return(-1);
    }
    stacka = ft_create_stacka(ac, argv);
    ft_check_duplicates(stacka);
    stackb = NULL;
    ft_rotate(&stacka, 'a');
    ft_printlst(stacka);
    //ft_putchar_fd('\n', 1);
    //ft_printlst(stackb);
    return(0);
}