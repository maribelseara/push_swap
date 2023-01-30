#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "./libft/libft.h"
# include <limits.h>
//borrar
# include <stdio.h>

typedef struct is_list
{
	int			    content;
	struct is_list	*next;
}	it_list;

void            ft_free_stack(it_list **stackx);
long long int   ft_atol(const char   *str);
void            ft_exit(it_list *stacka, it_list *stackb);
void            ft_exit(it_list *stacka, it_list *stackb);
it_list         *ft_ilstnew(int content);
void	        ft_ilstadd_back(it_list **lst, it_list *new);
it_list	        *ft_ilstlast(it_list *lst);
void			ft_swap (it_list **stackx, char stack_identifier);
int				ft_count_lst_items(it_list *lst);
void			ft_ss (it_list **stacka, it_list **stackb);
void    		ft_push(it_list **source, it_list **destination, char stackname);
//borrar
void    ft_printlst(it_list *lst);
#endif