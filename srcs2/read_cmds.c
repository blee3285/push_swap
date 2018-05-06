/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:13:05 by blee              #+#    #+#             */
/*   Updated: 2018/05/05 19:01:47 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		valid_cmd(char *cmd, char **names)
{
	int		id;

	id = cmd_id(cmd);
	if (id < 400 && names[id])
		if (ft_strcmp(cmd, names[id]) == 0)
			return (1);
	return (0);
}

void	do_cmd(char *cmd, t_num **lst_a, t_num **lst_b, swapf *cmds)
{
	int		id;

	id = cmd_id(cmd);
	cmds[id](lst_a, lst_b);
}

int		is_sorted(t_num *lst_a, t_num *lst_b)
{
	int		num;
	t_num	*temp;

	if (!lst_a || lst_b)
		return (0);
	num = lst_a->num;
	temp = lst_a->next;
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


int		ps_read_cmds(t_num **lst_a)
{
	int		ret;
	char	*buff;
	t_num	*lst_b;
	swapf	*cmds;
	char	**names;

	lst_b = NULL;
	cmds = ps_init_cmds();
	names = ps_cmd_names();
	while ((ret = get_next_line(0, &buff)) && ret != -1)
	{
		if (valid_cmd(buff, names))
			do_cmd(buff, lst_a, &lst_b, cmds);
		else
			ret = -1;
	}
	free(cmds);
	//ps_free_names(names);
	if (ret == -1)
		return (-1);
	if (is_sorted(*lst_a, lst_b))
		return (1);
	return (0);
}
