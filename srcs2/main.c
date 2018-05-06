/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:16:32 by blee              #+#    #+#             */
/*   Updated: 2018/05/05 19:03:57 by blee             ###   ########.fr       */
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

int	main(int ac, char **av)
{
	int		i;
	t_num	*lst_a;
	t_num	*lst_b;
	char	*line;
	swapf	*cmds;
	char	**names;

	i = 1;
	lst_a = NULL;
	lst_b = NULL;
	line = NULL;
	if (ac < 2)
		return (1);
	cmds = ps_init_cmds();
	names = ps_cmd_names();
	lst_a = ps_check_args(ac, av);
	if (!lst_a)
	{
		ft_printf("Error\n");
		return (0);
	}
	i = ps_read_cmds(&lst_a);
	if (i == 1)
		ft_printf("OK\n");
	else if (i == 0)
		ft_printf("KO\n");
	else if (i == -1)
		ft_printf("Error\n");
	/*
	while ((i = get_next_line(0, &line)))
	{
		ft_printf("cmd: %s\n", line);
		if (i == -1)
			break;
	}
	*/
	ps_freelst(lst_a);
	return (0);
}
