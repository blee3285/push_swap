/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 17:36:27 by blee              #+#    #+#             */
/*   Updated: 2018/07/13 19:47:30 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		cmp_top(t_num *lst)
{
	if (lst->order > lst->next->order)
		return (1);
	return (0);
}

void	ps_sort_three_b(t_num **lst_a, t_num **lst_b)
{
	int		smallest;
	t_num	*temp;

	smallest = 4;
	temp = *lst_b;
	while (temp)
	{
		if (temp->order < smallest)
			smallest = temp->order;
		temp = temp->next;
	}
	if ((*lst_b)->next->order == smallest)
		ps_rrb(lst_a, lst_b);
	else if ((*lst_b)->order == smallest)
		ps_rb(lst_a, lst_b);
	if ((*lst_b)->order < (*lst_b)->next->order)
		ps_sb(lst_a, lst_b);
}

void	ps_sort_b(t_num **lst_a, t_num **lst_b)
{
	int		len;

	len = ps_lst_size(*lst_b);
	if (len == 1)
		return ;
	else if (len == 2)
	{
		if ((*lst_b)->order < (*lst_b)->next->order)
			ps_sb(lst_a, lst_b);
		return ;
	}
	else if (len == 3)
		ps_sort_three_b(lst_a, lst_b);
}

void	ps_sort_four_plus(t_num **lst_a, t_num **lst_b, int len)
{
	while (!ps_check_order(*lst_a) && (ps_lst_size(*lst_a) > 3))
	{
		if ((ps_lst_size(*lst_b) >= 2) && cmp_top(*lst_a) && !cmp_top(*lst_b))
			ps_ss(lst_a, lst_b);
		else if (ps_lst_size(*lst_b) >= 2 && !cmp_top(*lst_b))
			ps_sb(lst_a, lst_b);
		else if (((*lst_a)->order > (len / 2)) && ps_lst_size(*lst_a) > 3)
			ps_ra(lst_a, lst_b);
		else if (cmp_top(*lst_a))
			ps_sa(lst_a, lst_b);
		else if ((*lst_a)->order <= (len / 2))
			ps_pb(lst_a, lst_b);
		else
			ps_ra(lst_a, lst_b);
	}
	if (!ps_check_order(*lst_a) && ps_lst_size(*lst_a) == 3)
		ps_sort_three(lst_a, lst_b);
	ps_sort_b(lst_a, lst_b);
	while (*lst_b)
		ps_pa(lst_a, lst_b);
}
