/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 16:45:50 by blee              #+#    #+#             */
/*   Updated: 2018/04/28 18:29:45 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_swap(t_num *lst)
{
	t_num	*temp;

	temp = lst->next;
	lst->next = temp->next;
	temp->next = lst;
}

void	ps_sa(t_num *a, t_num *b)
{
	t_num *temp;

	temp = b;
	ps_swap(a);
}

void	ps_sb(t_num *a, t_num *b)
{
	t_num *temp;

	temp = a;
	ps_swap(b);
}

void	ps_ss(t_num *a, t_num *b)
{
	ps_swap(a);
	ps_swap(b);
}
