/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseara <mseara@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:38:29 by mseara            #+#    #+#             */
/*   Updated: 2023/02/15 12:57:32 by mseara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "./libft/libft.h"
# include <limits.h>
//borrar
# include <stdio.h>

typedef struct s_ilist
{
	int				content;
	struct s_ilist	*next;
}	t_ilist;

void			ft_free_stack(t_ilist **stackx);
long long int	ft_atol(const char	 *str);
void			ft_exit(t_ilist *stacka, t_ilist *stackb);
void			ft_exit(t_ilist *stacka, t_ilist *stackb);
t_ilist			*ft_ilstnew(int content);
void			ft_ilstadd_back(t_ilist **lst, t_ilist *new);
t_ilist			*ft_ilstlast(t_ilist *lst);
void			ft_swap (t_ilist **stackx, char stackname);
int				ft_count_lst_items(t_ilist *lst);
void			ft_ss (t_ilist **stacka, t_ilist **stackb);
void			ft_push(t_ilist **source, t_ilist **destination, char stackname);
void			ft_rotate(t_ilist **stackx, char stackname);
void			ft_rr(t_ilist **stacka, t_ilist **stackb);
void			ft_reverse_rotate(t_ilist **stackx, char stackname);
void			ft_rrr(t_ilist **stacka, t_ilist **stackb);
int				ft_is_lst_sorted(t_ilist **stacka, t_ilist **stackb);
void			ft_filter_elements_number (t_ilist **stacka, t_ilist **stackb);
int				ft_get_median(t_ilist *stackx);
//borrar
void	ft_printlst(t_ilist *lst);
#endif
