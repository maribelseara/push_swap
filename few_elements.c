# include "push_swap.h"

static void    ft_sort_two(it_list **stacka, it_list **stackb)
{
    if (ft_is_lst_sorted(stacka, stackb) == 0)
        ft_swap(stacka, 'a');
}

void    ft_filter_elements_number (it_list **stacka, it_list **stackb)
{
    int elements;

    elements = ft_count_lst_items(*stacka);
    //printf("Elements: %d", elements);
    //ft_printlst(*stackb);
    if (elements == 2)
        ft_sort_two(stacka, stackb);
}
