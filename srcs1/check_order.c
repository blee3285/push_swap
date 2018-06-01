/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 17:10:42 by blee              #+#    #+#             */
/*   Updated: 2018/05/31 17:56:28 by blee             ###   ########.fr       */
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

int		ps_unordered(t_num *lst, int len)
{
	int		value;
	int		idx;
	int		order;
	t_num	*temp;

	value = 0;
	order = 1;
	if (len == 0)
		return (0);
	while (order <= len)
	{
		temp = lst;
		idx = 1;
		while (temp && (temp->order != order))
		{
			idx++;
			temp = temp->next;
		}
		value += idx_dist(order, idx, len);
		order++;
	}
	return (value);
}
