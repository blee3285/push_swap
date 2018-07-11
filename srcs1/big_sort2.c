/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:19:58 by blee              #+#    #+#             */
/*   Updated: 2018/07/10 16:28:15 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_num **lst_a, t_num **lst_b, int min, int max)
{
	int		mid;
	int		i;

	mid = (min + max + 1) / 2;
	i = min;
	while ((i <= max) && (*lst_b))
	{
		if ((*lst_b)->order >= mid)
			ps_pa(lst_a, lst_b);
		else
			ps_rb(lst_a, lst_b);
		i++;
	}
}

void	push_to_b(t_num **lst_a, t_num **lst_b, int min, int max)
{
	int		mid;
	int		i;

	mid = (min + max + 1) / 2;
	i = min;
	while ((i <= max) && (*lst_a))
	{
		if ((*lst_a)->order < mid)
			ps_pb(lst_a, lst_b);
		else
			ps_ra(lst_a, lst_b);
		i++;
	}
}
