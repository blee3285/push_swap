/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:28:35 by blee              #+#    #+#             */
/*   Updated: 2018/06/12 18:27:30 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_big_sort_b(t_num **lst_a, t_num **lst_b, int len)
{

}

int		ps_big_sort(t_num **lst_a, t_num **lst_b, int len)
{
	int		mid;
	int		i;

	mid = len / 2;
	i = 0;
	while (i < len)
	{
		if ((*lst_a)->order < mid)
			ps_pb(lst_a, lst_b);
		else
			ps_ra(lst_a, lst_b);
		i++;
	}
	return (0);
}
