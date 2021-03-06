/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:06:11 by blee              #+#    #+#             */
/*   Updated: 2018/07/10 16:52:37 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_push(t_num **a, t_num **b)
{
	t_num	*head;
	t_num	*temp;

	if (!(*a))
		return ;
	head = *a;
	temp = head->next;
	*a = temp;
	if (*b)
	{
		head->next = *b;
		*b = head;
	}
	else
	{
		head->next = NULL;
		*b = head;
	}
}

void	ps_pa(t_num **a, t_num **b)
{
	ps_push(b, a);
}

void	ps_pb(t_num **a, t_num **b)
{
	ps_push(a, b);
}
