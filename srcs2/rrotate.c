/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:07:55 by blee              #+#    #+#             */
/*   Updated: 2018/05/02 18:35:07 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_rrotate(t_num **lst)
{
	t_num	*temp;
	t_num	*temp2;

	if (!(*lst))
		return ;
	temp = *lst;
	temp2 = NULL;
	if (!(temp->next))
		return ;
	while (temp->next)
	{
		temp2 = temp;
		temp = temp->next;
	}
	temp2->next = NULL;
	temp->next = *lst;
	*lst = temp;
}

void	ps_rra(t_num **a, t_num **b)
{
	t_num	*temp;

	temp = *b;
	ps_rrotate(a);
}

void	ps_rrb(t_num **a, t_num **b)
{
	t_num	*temp;

	temp = *a;
	ps_rrotate(b);
}

void	ps_rrr(t_num **a, t_num **b)
{
	ps_rrotate(a);
	ps_rrotate(b);
}
