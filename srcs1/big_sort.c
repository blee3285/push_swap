/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:28:35 by blee              #+#    #+#             */
/*   Updated: 2018/07/03 20:21:48 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_other(t_num **lst_a, t_num **lst_b, int min, int max, char ab)
{
	int	mid;
	int	i;

	mid = (min + max) / 2;
	i = min;
	if (ab == 'a')
		while (i++ <= max)
		{
			if ((*lst_a)->order < mid)
				ps_pb(lst_a, lst_b);
			else
				ps_ra(lst_a, lst_b);
		}
	else if (ab == 'b')
		while (i++ <= max)
		{
			if ((*lst_b)->order >= mid)
				ps_pa(lst_a, lst_b);
			else
				ps_rb(lst_a, lst_b);
		}
}

void	rot_back(t_num **lst_a, t_num **lst_b, int len, char ab)
{
	if (ab == 'a')
		while (len--)
			ps_rra(lst_a, lst_b);
	else if (ab == 'b')
		while (len--)
			ps_rrb(lst_a, lst_b);
}

void	quick_sort_a(t_num **lst_a, t_num **lst_b, int min, int max)
{
	int		mid;
	int		i;
	int		len;

	mid = (min + max) / 2;
	len = max - min + 1;
	i = min;
	if (len < 2)
		return ;
	else if (len < 3)
	{
		if ((*lst_a)->order > (*lst_a)->next->order)
			ps_sa(lst_a, lst_b);
		return ;
	}
	push_to_other(lst_a, lst_b, min, max, 'a');
	rot_back(lst_a, lst_b, (max - mid + 1), 'a');
	quick_sort_a(lst_a, lst_b, mid, max);
	quick_sort_b(lst_a, lst_b, min, (mid - 1));
}

void	quick_sort_b(t_num **lst_a, t_num **lst_b, int min, int max)
{
	int		mid;
	int		i;
	int		len;

	mid = (min + max) / 2;
	len = max - min + 1;
	i = min;
	if (len < 2)
	{
		ps_pa(lst_a, lst_b);
		return ;
	}
	else if (len == 2)
	{
		if ((*lst_b)->order > (*lst_b)->next->order)
			ps_sb(lst_a, lst_b);
		while ((*lst_b))
			ps_pa(lst_a, lst_b);
		return ;
	}
	push_to_other(lst_a, lst_b, min, max, 'b');
	rot_back(lst_a, lst_b, (mid - min + 1), 'b');
	quick_sort_a(lst_a, lst_b, mid, max);
	quick_sort_b(lst_a, lst_b, min, (mid - 1));
}

void	ps_big_sort(t_num **lst_a, t_num **lst_b, int min, int max)
{
	int		mid;
	int		i;

	mid = (min + max) / 2;
	i = min;
	if ((max - min + 1) < 2)
		return ;
	else if ((max - min + 1) < 3)
	{
		if ((*lst_a)->order > (*lst_a)->next->order)
			ps_sa(lst_a, lst_b);
		return ;
	}
	push_to_other(lst_a, lst_b, min, max, 'a');
	ps_big_sort(lst_a, lst_b, mid, max);
	quick_sort_b(lst_a, lst_b, min, (mid - 1));
}
