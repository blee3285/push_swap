/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:26:49 by blee              #+#    #+#             */
/*   Updated: 2018/04/24 20:43:00 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*ps_newlst(int num)
{
	t_num	*new;

	new = (t_num*)malloc(sizeof(t_num));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}

void	ps_addlst(t_num *lst, t_num *new)
{
	t_num	*temp;

	temp = lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;

}
