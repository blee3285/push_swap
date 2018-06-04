/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:01:34 by blee              #+#    #+#             */
/*   Updated: 2018/06/03 15:22:38 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_to_smallest(t_num **lst_a, t_num **lst_b, int curr, int dir)
{
	if (dir)
	{
		while ((*lst_a) && (*lst_a)->order != curr)
			ps_ra(lst_a, lst_b);
	}
	else
	{
		while ((*lst_a) && (*lst_a)->order != curr)
			ps_rra(lst_a, lst_b);
	}
}

void	push_smallest(t_num **lst_a, t_num **lst_b, int len, int curr)
{
	int		dist;
	t_num	*temp;

	temp = *lst_a;
	dist = 0;
	while (temp && temp->order != curr)
	{
		dist++;
		temp = temp->next;
	}
	rot_to_smallest(lst_a, lst_b, curr, (dist <= (len / 2)));
	ps_pb(lst_a, lst_b);
}

int		ps_med_sort(t_num **lst_a, t_num **lst_b, int len)
{
	int		curr;
	int		temp_len;

	curr = 1;
	temp_len = len;
	while (temp_len > 3)
	{
		push_smallest(lst_a, lst_b, temp_len, curr);
		curr++;
		temp_len--;
	}
	ps_small_sorts(lst_a, lst_b, len);
	while (*lst_b)
		ps_pa(lst_a, lst_b);
	return (0);
}
