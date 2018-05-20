/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:43:55 by blee              #+#    #+#             */
/*   Updated: 2018/05/19 17:42:56 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/includes/libft.h"

typedef struct		s_num
{
	int				num;
	int				order;
	struct s_num	*next;
}					t_num;

typedef void		(*swapf)(t_num**, t_num**);

t_num	*ps_newlst(int num);
void	ps_addlst(t_num *lst, t_num *new);
void	ps_buildlst(t_num **lst, char *num);
void	ps_freelst(t_num *lst);

void	ps_sa(t_num **a, t_num **b);
void	ps_sb(t_num **a, t_num **b);
void	ps_ss(t_num **a, t_num **b);
void	ps_pa(t_num **a, t_num **b);
void	ps_pb(t_num **a, t_num **b);
void	ps_ra(t_num **a, t_num **b);
void	ps_rb(t_num **a, t_num **b);
void	ps_rr(t_num **a, t_num **b);
void	ps_rra(t_num **a, t_num **b);
void	ps_rrb(t_num **a, t_num **b);
void	ps_rrr(t_num **a, t_num **b);

t_num	*ps_check_args(int ac, char **av);
int		ps_error();

int		int_max_check(char *num);

int		int_max_check(char *num);

#endif
