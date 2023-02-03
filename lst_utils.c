# include "push_swap.h"

it_list	*ft_ilstnew(int content)
{
	it_list	*lst;

	lst = malloc(sizeof(it_list) * 1);
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

it_list	*ft_ilstlast(it_list *lst)
{
	it_list	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_ilstadd_back(it_list **lst, it_list *new)
{
	it_list	*last;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last = ft_ilstlast(*lst);
			last->next = new;
		}
	}
}

int	ft_count_lst_items(it_list *lst)
{
	int	items;

	items = 1;
	if (!lst)
		return (items);
	while(lst->next)
	{
		items++;
		lst = lst->next;
	}
	return (items);
}

int	ft_is_lst_sorted(it_list **stacka, it_list **stackb)
{
	it_list	*tmp;

	if ((*stackb))
		return (0);
	tmp = *stacka;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return(1);
}
