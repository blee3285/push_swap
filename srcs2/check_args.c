/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:12:51 by blee              #+#    #+#             */
/*   Updated: 2018/05/05 16:31:47 by blee             ###   ########.fr       */
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

t_num	*ps_check_args(int ac, char **av)
{
	t_num	*lst;
	int		i;

	lst = NULL;
	i = 1;
	while (i < ac)
	{
		if (is_valid(av[i]))
			ps_buildlst(&lst, av[i]);
		else
		{
			ps_freelst(lst);
			return (NULL);
		}
		i++;
	}
	return (lst);
}
