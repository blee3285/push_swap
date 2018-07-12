/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:42:44 by blee              #+#    #+#             */
/*   Updated: 2018/07/11 17:13:49 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		lst_len(t_num *lst)
{
	int		i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		i += 1;
		lst = lst->next;
	}
	return (i);
}

void	print_lst(t_num *lst)
{
	if (lst)
		ft_printf("%d ", lst->num);
	else
		return ;
	if (lst->next)
		print_lst(lst->next);
}

void	ps_print_lst(t_num *lst_a, t_num *lst_b)
{
	ft_putstr("A: ");
	print_lst(lst_a);
	ft_putstr("\n");
	ft_putstr("B: ");
	print_lst(lst_b);
	ft_putstr("\n----------\n");
}
