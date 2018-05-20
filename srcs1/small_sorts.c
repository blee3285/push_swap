/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:16:57 by blee              #+#    #+#             */
/*   Updated: 2018/05/19 17:48:18 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_lst_size(t_num *lst)
{
	int		i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ps_sort_two(t_num **lst_a, t_num **lst_b)
{
	t_num	*a;
	t_num	*temp;

	a = *lst_a;
	temp = a->next;
	if (a->num > temp->num)
		ps_sa(lst_a, lst_b);
}

void	ps_sort_three(t_num **lst_a, t_num **lst_b)
{
	t_num	*a;

	a = *lst_a;
	if (a->order ==  2)
		ps_sa(lst_a, lst_b);
}

int		ps_small_sorts(t_num **lst_a, t_num **lst_b, int len)
{
	if (len == 0)
		return (0);
	else if (len == 1)
		return (1);
	else if (len == 2)
		ps_sort_two(lst_a, lst_b);
	else if (len == 3)
		ps_sort_three(lst_a, lst_b);
	return (1);
}
