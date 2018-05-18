/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:16:57 by blee              #+#    #+#             */
/*   Updated: 2018/05/17 19:02:20 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psuh_swap.h"

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

void	ps_sort_small(t_num **lst, int len)
{
	if (len == 2)
	{

	}
	else if (len == 3)
	{
	}
}

void	ps_sort_medium(t_num **lst_a, t_num **lst_b, int len)
{
}

int		ps_small_sorts(t_num **lst_a, t_num **lst_b, int len);
{
	if (len == 0)
		return (0);
	else if (len == 1)
		return (1);
	else if (len < 4)

}
