/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:42:44 by blee              #+#    #+#             */
/*   Updated: 2018/05/12 15:56:11 by blee             ###   ########.fr       */
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

int		print_one_num(t_num *lst, int cur, int len)
{
	if (len >= cur)
	{
		ft_putnbr(lst->num);
		return (1);
	}
	else
		ft_putchar(' ');
	return (0);
}

void	ps_print_lst(t_num *lst_a, t_num *lst_b)
{
	int		a_len;
	int		b_len;
	int		cur;

	a_len = lst_len(lst_a);
	b_len = lst_len(lst_b);
	if (a_len > b_len)
		cur = a_len;
	else
		cur = b_len;
	while (cur > 0)
	{
		if (print_one_num(lst_a, cur, a_len))
			lst_a = lst_a->next;
		ft_putchar(' ');
		if (print_one_num(lst_b, cur, b_len))
			lst_b = lst_b->next;
		ft_putchar('\n');
		cur--;
	}
	ft_printf("_ _\na b\n");
	ft_printf("-----\n");
}
