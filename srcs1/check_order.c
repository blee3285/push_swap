/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 17:10:42 by blee              #+#    #+#             */
/*   Updated: 2018/06/03 15:46:35 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_check_order(t_num *lst)
{
	int		order;

	order = 1;
	while (lst != NULL)
	{
		if (order != lst->order)
			return (0);
		order++;
		lst = lst->next;
	}
	return (1);
}

int		idx_dist(int order, int idx, int len)
{
	int		dist;

	dist = idx - order;
	if (dist < 0)
		dist *= -1;
	if (dist > (len / 2))
		return (len - dist);
	return (dist);
}

int		num_idx(t_num *lst, int order)
{
	int		i;

	i = 0;
	while (lst->order != order)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int		ps_unordered(t_num *lst, int len)
{
	int		value;
	int		idx_a;
	int		idx_b;
	int		cur;

	value = 0;
	idx_a = 0;
	cur = len;
	while (cur > 0)
	{
		idx_b = num_idx(lst, cur);
		value += idx_dist(idx_a, idx_b, len);
		idx_a = idx_b;
		cur--;
	}
	return (value);
}
