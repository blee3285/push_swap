/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:12:51 by blee              #+#    #+#             */
/*   Updated: 2018/05/09 18:28:28 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int		has_dup(t_num *lst)
{
	int		i;

	if (!lst)
		return (0);
	i = lst->num;
	while (lst->next)
	{
		lst = lst->next;
		if (i == lst->num)
			return (1);
	}
	return (0);
}

int		no_dups(t_num *lst)
{
	t_num	*temp;
	int		i;

	if (!lst)
		return (0);
	temp = lst;
	i = temp->num;
	while (temp->next)
	{
		if (has_dup(temp))
			return (0);
		temp = temp->next;
	}
	return (1);
}

t_num	*ps_check_args(int ac, char **av)
{
	t_num	*lst;
	int		i;
	int		ret;

	lst = NULL;
	i = 1;
	ret = 1;
	while (i < ac)
	{
		if (is_valid(av[i]))
			ps_buildlst(&lst, av[i]);
		else
			ret = 0;
		i++;
	}
	if (no_dups(lst) && ret)
		return (lst);
	else
	{
		ps_freelst(lst);
		return (NULL);
	}
}
