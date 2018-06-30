/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:28:35 by blee              #+#    #+#             */
/*   Updated: 2018/06/29 17:35:29 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_back(t_num **lst_a, t_num **lst_b, int x, char ab)
{

}

void	quick_sort_b(t_num **lst_a, t_num **lst_b, int min, int max)
{
	int		mid;
	int		i;

	mid = (min + max) / 2;
	i = 0;
	while (i < (max - mid))
	{
		if ((*lst_b)->order >= mid)
			ps_pa(lst_a, lst_b);
		else
			ps_rb(lst_a, lst_b);
		i++;
	}
}

void	quick_sort_a(t_num **lst_a, t_num **lst_b, int min, int max)
{
	int		mid;
	int		i;

	mid = (min + max) / 2;
	i = 0;
	if ((max - min) < 2)
		return ;
	else if ((max - min) < 3)
	{
		if ((*lst_a)->order > (*lst_a)->next->order)
			ps_sa(lst_a, lst_b);
		return ;
	}
	while (i < (max - min))
	{
		if ((*lst_a)->order < mid)
			ps_pb(lst_a, lst_b);
		else
			ps_ra(lst_a, lst_b);
		i++;
	}
	//if not the first call, rotate back the numbers you didn't push
	quick_sort_a(lst_a, lst_b, mid, max);
	quick_sort_b(lst_a, lst_b, min, (mid - 1));
}

int		ps_big_sort(t_num **lst_a, t_num **lst_b, int len)
{
	return (0);
}
