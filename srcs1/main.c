/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:15:31 by blee              #+#    #+#             */
/*   Updated: 2018/07/10 16:16:05 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_num *lst)
{
	if (lst)
		ft_printf("%d ", lst->num);
	else
		return ;
	if (lst->next)
		print_lst(lst->next);
}

void	print_order(t_num *lst)
{
	if (lst)
		ft_printf("%d ", lst->order);
	else
		return ;
	if (lst->next)
		print_order(lst->next);
}

int		ps_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	int		size;
	t_num	*lst_a;
	t_num	*lst_b;

	if (ac < 2)
		return (0);
	i = 1;
	lst_b = NULL;
	lst_a = ps_check_args(ac, av);
	if (!lst_a)
		return (ps_error());
	size = ps_lst_size(lst_a);
	if (size > 40)
		ps_big_sort(&lst_a, &lst_b, 1, size);
	else if (size > 3)
		ps_med_sort(&lst_a, &lst_b, size);
	else
		ps_small_sorts(&lst_a, &lst_b, size);
	ps_freelst(lst_a);
	return (0);
}
