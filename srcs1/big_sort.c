/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:28:35 by blee              #+#    #+#             */
/*   Updated: 2018/07/10 18:31:23 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		len;
	int		mid;

	len = max - min + 1;
	mid = (max + min + 1) / 2;
	if (len < 2)
		return ;
	else if (len == 2)
	{
		if ((*lst_a)->order > (*lst_a)->next->order)
			ps_sa(lst_a, lst_b);
		return ;
	}
	push_to_b(lst_a, lst_b, min, max);
	rot_back(lst_a, lst_b, (max - mid + 1), 'a');
	quick_sort_a(lst_a, lst_b, mid, max);
	quick_sort_b(lst_a, lst_b, min, (mid - 1));
}

void	quick_sort_b(t_num **lst_a, t_num **lst_b, int min, int max)
{
	int		len;
	int		mid;

	len = max - min + 1;
	mid = (max + min + 1) / 2;
	if (len < 2)
	{
		ps_pa(lst_a, lst_b);
		return ;
	}
	else if (len == 2)
	{
		if ((*lst_b)->order < (*lst_b)->next->order)
			ps_sb(lst_a, lst_b);
		ps_pa(lst_a, lst_b);
		ps_pa(lst_a, lst_b);
		return ;
	}
	push_to_a(lst_a, lst_b, min, max);
	rot_back(lst_a, lst_b, (mid - min), 'b');
	quick_sort_a(lst_a, lst_b, mid, max);
	quick_sort_b(lst_a, lst_b, min, (mid - 1));
}

void	ps_big_sort(t_num **lst_a, t_num **lst_b, int min, int max)
{
	int		len;
	int		mid;

	len = max - min + 1;
	mid = (max + min + 1) / 2;
	if (len < 2)
		return ;
	else if (len == 2)
	{
		if ((*lst_a)->order > (*lst_a)->next->order)
			ps_sa(lst_a, lst_b);
		return ;
	}
	push_to_a(lst_a, lst_b, min, max);
	ps_big_sort(lst_a, lst_b, mid, max);
	quick_sort_b(lst_a, lst_b, min, (mid - 1));
}
