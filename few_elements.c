# include "push_swap.h"

static void    ft_sort_two(it_list **stacka, it_list **stackb)
{
    if (ft_is_lst_sorted(stacka, stackb) == 0)
        ft_swap(stacka, 'a');
}

static void ft_sort_three_else(it_list **stacka)
{
    if ((*stacka)->content < (*stacka)->next->next->content)
            ft_swap(stacka, 'a');
        else
        {
            if ((*stacka)->next->content < (*stacka)->next->next->content)
                ft_rotate(stacka, 'a');
            else
            {
                ft_swap(stacka, 'a');
                ft_reverse_rotate(stacka, 'a');
            }
        }
}

static void ft_sort_three(it_list **stacka, it_list **stackb)
{
    if (ft_is_lst_sorted(stacka, stackb))
        return;
    if ((*stacka)->content < (*stacka)->next->content)
    {
        if ((*stacka)->content < (*stacka)->next->next->content)
        {
            ft_swap(stacka, 'a');
            ft_rotate(stacka, 'a');
        }
        else
            ft_reverse_rotate(stacka, 'a');
    }
    else
       ft_sort_three_else(stacka); 
}

void    ft_filter_elements_number (it_list **stacka, it_list **stackb)
{
    int elements;

    elements = ft_count_lst_items(*stacka);
    if (elements == 2)
        ft_sort_two(stacka, stackb);
    else if (elements == 3)
        ft_sort_three(stacka, stackb);
}
