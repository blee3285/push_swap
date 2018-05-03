/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:22:44 by blee              #+#    #+#             */
/*   Updated: 2018/05/02 18:32:36 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "../libft/includes/libft.h"

typedef struct		s_num
{
	int				num;
	struct s_num	*next;
}					t_num;

typedef	void		(*swapf)(t_num**, t_num**);

t_num	*ps_newlst(int num);
void	ps_addlst(t_num *lst, t_num *new);
void	ps_buildlst(t_num **lst, char *num);

swapf	*init_cmds();
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

#endif
