/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:16:32 by blee              #+#    #+#             */
/*   Updated: 2018/05/07 15:30:33 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_lst(t_num *lst)
{
	if (lst)
		ft_printf("%d ", lst->num);
	else
		return ;
	if (lst->next)
		print_lst(lst->next);
}

void	print_out(int num)
{
	if (num == 1)
		ft_printf("OK\n");
	else if (num == 0)
		ft_printf("KO\n");
	else if (num == -1)
		write(2, "Error\n", 6);
}

int	main(int ac, char **av)
{
	int		i;
	t_num	*lst_a;

	i = 1;
	lst_a = NULL;
	if (ac < 2)
		return (1);
	lst_a = ps_check_args(ac, av);
	if (!lst_a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = ps_read_cmds(&lst_a);
	print_out(i);
	ps_freelst(lst_a);
	return (0);
}
