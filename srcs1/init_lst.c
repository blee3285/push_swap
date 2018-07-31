/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:26:49 by blee              #+#    #+#             */
/*   Updated: 2018/07/30 19:45:56 by blee             ###   ########.fr       */
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
	new->order = 1;
	new->next = NULL;
	return (new);
}

void	update_order(t_num *lst, t_num *new)
{
	if (new->num < lst->num)
		lst->order += 1;
	else
		new->order += 1;
}

void	ps_addlst(t_num *lst, t_num *new)
{
	t_num	*temp;

	temp = lst;
	while (temp->next)
	{
		update_order(temp, new);
		temp = temp->next;
	}
	update_order(temp, new);
	temp->next = new;
}

void	ps_buildlst(t_num **lst, char *num)
{
	t_num	*new;
	int		i;

	new = NULL;
	i = 0;
	while (num[i])
	{
		if (ft_isdigit(num[i]) || num[i] == '-')
		{
			new = ps_newlst(ft_atoi(&num[i]));
			if (!*lst)
				*lst = new;
			else
				ps_addlst(*lst, new);
			while ((ft_isdigit(num[i]) || num[i] == '-') && num[i])
				i++;
			i--;
		}
		i++;
	}
}

void	ps_freelst(t_num *lst)
{
	if (!lst)
		return ;
	if (lst->next)
		ps_freelst(lst->next);
	free(lst);
}
