/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 17:10:42 by blee              #+#    #+#             */
/*   Updated: 2018/05/19 17:17:42 by blee             ###   ########.fr       */
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
