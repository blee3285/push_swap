/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:16:32 by blee              #+#    #+#             */
/*   Updated: 2018/04/24 20:45:40 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_num *lst)
{
	ft_printf("%d ", lst->num);
	if (lst->next)
		print_lst(lst->next);
}

void	ps_freelst(t_num *lst)
{
	if (!lst)
		return ;
	if (lst->next)
		ps_freelst(lst->next);
	free(lst);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	t_num	*list;
	t_num	*new;

	i = 1;
	j = 0;
	list = NULL;
	new = NULL;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
			{
				new = ps_newlst(ft_atoi(&av[i][j]));
				if (!list)
					list = new;
				else
					ps_addlst(list, new);
			}
			j++;
		}
		i++;
	}
	print_lst(list);
	ft_putchar('\n');
	ps_freelst(list);
	return (0);
}
