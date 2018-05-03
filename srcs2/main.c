/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:16:32 by blee              #+#    #+#             */
/*   Updated: 2018/05/02 18:34:36 by blee             ###   ########.fr       */
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
	t_num	*lst_a;
	t_num	*lst_b;
	char	*line;
	swapf	*cmds;

	i = 1;
	lst_a = NULL;
	lst_b = NULL;
	line = NULL;
	if (ac < 2)
		return (1);
	cmds = init_cmds();
	while (i < ac)
	{
		ps_buildlst(&lst_a, av[i]);
		i++;
	}
	print_lst(lst_a);
	ft_putchar('\n');
	cmds['p' + 'b'](&lst_a, &lst_b);
	cmds['p' + 'b'](&lst_a, &lst_b);
	cmds['p' + 'b'](&lst_a, &lst_b);
	cmds['r' + 'r' + 'r'](&lst_a, &lst_b);
	print_lst(lst_a);
	ft_putchar('\n');
	print_lst(lst_b);
	ft_putchar('\n');
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
