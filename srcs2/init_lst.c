/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:26:49 by blee              #+#    #+#             */
/*   Updated: 2018/07/11 17:20:24 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ps_buildlst(t_num **lst, char *num, int flag)
{
	t_num	*new;
	int		i;

	new = NULL;
	i = 0;
	if (flag && num[0] == '-' && num[1] == 'v')
		i += 2;
	while (num[i])
	{
		if (ft_isdigit(num[i]))
		{
			new = ps_newlst(ft_atoi(&num[i]));
			if (!*lst)
				*lst = new;
			else
				ps_addlst(*lst, new);
			while (num[i] && ft_isdigit(num[i]))
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
