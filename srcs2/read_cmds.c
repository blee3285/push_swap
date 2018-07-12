/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:13:05 by blee              #+#    #+#             */
/*   Updated: 2018/07/11 17:47:01 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		valid_cmd(char *cmd, char **names)
{
	int		id;

	id = cmd_id(cmd);
	if ((id > 0 && id < 49) && names[id] != NULL)
	{
		if (ft_strcmp(cmd, names[id]) == 0)
			return (1);
	}
	return (0);
}

int		is_sorted(t_num *lst_a, t_num *lst_b)
{
	int		num;
	t_num	*temp;

	if (lst_b)
	{
		ps_freelst(lst_b);
		return (0);
	}
	if (!lst_a)
		return (0);
	num = lst_a->num;
	temp = lst_a;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->num >= num)
			num = temp->num;
		else
			return (0);
	}
	return (1);
}

void	print_cmd(t_num *lst_a, t_num *lst_b, char *cmd, int v)
{
	if (v)
	{
		ft_printf("Exec %s\n", cmd);
		ps_print_lst(lst_a, lst_b);
	}
}

int		ps_do_cmds(t_num **lst_a, t_num **lst_b, int v)
{
	int		ret;
	char	*buff;
	t_swapf	*cmds;
	char	**names;

	cmds = ps_init_cmds();
	names = ps_cmd_names();
	ret = 0;
	while ((ret != -1) && (ret = get_next_line(0, &buff)))
	{
		if (valid_cmd(buff, names))
		{
			cmds[cmd_id(buff)](lst_a, lst_b);
			print_cmd(*lst_a, *lst_b, buff, v);
		}
		else
			ret = -1;
	}
	free(cmds);
	ps_free_names(names);
	if (ret == -1)
		return (-1);
	return (0);
}

int		ps_read_cmds(t_num **lst_a, int flag)
{
	int		ret;
	t_num	*lst_b;

	lst_b = NULL;
	if (flag)
	{
		ft_putstr("Init a and b:\n");
		ps_print_lst(*lst_a, lst_b);
	}
	ret = ps_do_cmds(lst_a, &lst_b, flag);
	if (ret == -1)
		return (-1);
	if (is_sorted(*lst_a, lst_b))
		return (1);
	return (0);
}
