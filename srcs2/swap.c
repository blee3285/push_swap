/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 16:45:50 by blee              #+#    #+#             */
/*   Updated: 2018/05/07 15:23:58 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_swap(t_num **lst)
{
	t_num	*head;
	t_num	*temp;

	if (!(*lst))
		return ;
	head = *lst;
	if (!(head->next))
		return ;
	temp = head->next;
	head->next = temp->next;
	temp->next = head;
	*lst = temp;
}

void	ps_sa(t_num **a, t_num **b)
{
	t_num	**temp;

	temp = b;
	ps_swap(a);
}

void	ps_sb(t_num **a, t_num **b)
{
	t_num	**temp;

	temp = a;
	ps_swap(b);
}

void	ps_ss(t_num **a, t_num **b)
{
	ps_swap(a);
	ps_swap(b);
}
