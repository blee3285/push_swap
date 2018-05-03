/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:36:55 by blee              #+#    #+#             */
/*   Updated: 2018/05/02 17:50:06 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_rotate(t_num **lst)
{
	t_num	*temp;
	t_num	*node;

	if (!*lst)
		return ;
	temp = *lst;
	node = *lst;
	if (!(temp->next))
		return ;
	*lst = temp->next;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
	node->next = NULL;
}

void	ps_ra(t_num **a, t_num **b)
{
	t_num	*temp;

	temp = *b;
	ps_rotate(a);
}

void	ps_rb(t_num **a, t_num **b)
{
	t_num	*temp;

	temp = *a;
	ps_rotate(b);
}

void	ps_rr(t_num **a, t_num **b)
{
	ps_rotate(a);
	ps_rotate(b);
}
