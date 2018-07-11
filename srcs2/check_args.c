/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:12:51 by blee              #+#    #+#             */
/*   Updated: 2018/07/10 19:52:04 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_valid(char *str, int flag)
{
	int			i;

	i = 0;
	if (flag)
		if (str[0] == '-' && str[1] == 'v')
			i += 2;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			if (!int_max_check(&str[i]))
				return (0);
			while (ft_isdigit(str[i]))
				i++;
		}
		else if (str[i] == ' ')
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

	if (!lst)
		return (0);
	temp = lst;
	while (temp->next)
	{
		if (has_dup(temp))
			return (0);
		temp = temp->next;
	}
	return (1);
}

t_num	*ps_check_args(int ac, char **av, int flag)
{
	t_num	*lst;
	int		i;
	int		ret;

	lst = NULL;
	i = 1;
	ret = 1;
	while (i < ac && ret)
	{
		if (is_valid(av[i], flag))
			ps_buildlst(&lst, av[i], flag);
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
