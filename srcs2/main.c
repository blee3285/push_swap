/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:16:32 by blee              #+#    #+#             */
/*   Updated: 2018/04/28 16:20:54 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	t_num	*list;
	char	*line;

	i = 1;
	list = NULL;
	line = NULL;
	if (ac < 2)
		return (1);
	while (i < ac)
	{
		ps_buildlst(&list, av[i]);
		i++;
	}
	print_lst(list);
	ft_putchar('\n');
	while ((i = get_next_line(0, &line)))
	{
		ft_printf("cmd: %s\n", line);
		if (i == -1)
			break;
	}
	ps_freelst(list);
	return (0);
}
