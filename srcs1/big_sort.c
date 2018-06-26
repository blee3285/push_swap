/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:28:35 by blee              #+#    #+#             */
/*   Updated: 2018/06/25 17:03:35 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_swap(t_num **lst_a, t_num **lst_b, char ab)
{
	if (ab == 'a')
	{
		if (*lst_a && (*lst_a)->next)
			if ((*lst_a)->order > (*lst_a)->next->order)
				ps_sa(lst_a, lst_b);
	}
	else if (ab == 'b')
	{
		if (*lst_b && (*lst_b)->next)
			if ((*lst_b)->order > (*lst_b)->next->order)
				ps_sb(lst_a, lst_b);
	}
}

void	ps_big_sort_b(t_num **lst_a, t_num **lst_b, int min, int max)
{
	int		mid;
	int		i;

	mid = (min + max) / 2;
	i = 0;
	if (max - min < 2)
	{
		while (*lst_b)
			ps_pa(lst_a, lst_b);
		return ;
	}
	while (i < (max - min))
	{
		if ((*lst_b)->order >= mid)
		{
			ps_pa(lst_a, lst_b);
			mini_swap(lst_a, lst_b, 'a');
		}
		else
			ps_rb(lst_a, lst_b);
		i++;
	}
	ps_big_sort_b(lst_a, lst_b, min, (mid - 1));
}

void	ps_big_sort_a(t_num **lst_a, t_num **lst_b, int min, int max)
{
	int		mid;
	int		i;

	mid = (min + max) / 2;
	i = 0;
	if ((max - min) < 4)
		return ;
	while (i < (max - min))
	{
		if ((*lst_a)->order < mid)
		{
			ps_pb(lst_a, lst_b);
			mini_swap(lst_a, lst_b, 'b');
		}
		else
			ps_ra(lst_a, lst_b);
		i++;
	}
	ps_big_sort_a(lst_a, lst_b, mid, max);
}

int		ps_big_sort(t_num **lst_a, t_num **lst_b, int len)
{
	while ((ps_unordered(*lst_a, len) / len) > 3)
	{
		ps_big_sort_a(lst_a, lst_b, 0, len);
		ps_big_sort_b(lst_a, lst_b, 0, (len - 3));
	}
	ps_med_sort(lst_a, lst_b, len);
	return (0);
}
