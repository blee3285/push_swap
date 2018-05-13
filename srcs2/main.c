/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:16:32 by blee              #+#    #+#             */
/*   Updated: 2018/05/12 18:37:12 by blee             ###   ########.fr       */
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

int		check_flag(char* str)
{
	if (str[0] == '-')
		if(str[1] == 'v')
			return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	int		v_flag;
	t_num	*lst_a;

	if (ac < 2)
		return (0);
	i = 1;
	v_flag = check_flag(av[1]);
	if (ac < 3 && v_flag)
		return (0);
	lst_a = NULL;
	lst_a = ps_check_args(ac, av);
	if (!lst_a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = ps_read_cmds(&lst_a, v_flag);
	print_out(i);
	ps_freelst(lst_a);
	return (0);
}
