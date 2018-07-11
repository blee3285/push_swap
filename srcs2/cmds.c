/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:17:00 by blee              #+#    #+#             */
/*   Updated: 2018/07/10 16:50:50 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

swapf	*ps_init_cmds(void)
{
	swapf	*cmds;

	cmds = (swapf*)malloc(sizeof(swapf*) * 50);
	if (!cmds)
		return (NULL);
	ft_bzero(cmds, sizeof(swapf*) * 50);
	cmds[cmd_id("sa")] = &ps_sa;
	cmds[cmd_id("sb")] = &ps_sb;
	cmds[cmd_id("ss")] = &ps_ss;
	cmds[cmd_id("pa")] = &ps_pa;
	cmds[cmd_id("pb")] = &ps_pb;
	cmds[cmd_id("ra")] = &ps_ra;
	cmds[cmd_id("rb")] = &ps_rb;
	cmds[cmd_id("rr")] = &ps_rr;
	cmds[cmd_id("rra")] = &ps_rra;
	cmds[cmd_id("rrb")] = &ps_rrb;
	cmds[cmd_id("rrr")] = &ps_rrr;
	return (cmds);
}

char	**ps_cmd_names(void)
{
	char	**names;

	names = (char**)malloc(sizeof(char*) * 50);
	if (!names)
		return (NULL);
	ft_bzero(names, sizeof(char*) * 50);
	names[cmd_id("sa")] = ft_strdup("sa");
	names[cmd_id("sb")] = ft_strdup("sb");
	names[cmd_id("ss")] = ft_strdup("ss");
	names[cmd_id("pa")] = ft_strdup("pa");
	names[cmd_id("pb")] = ft_strdup("pb");
	names[cmd_id("ra")] = ft_strdup("ra");
	names[cmd_id("rb")] = ft_strdup("rb");
	names[cmd_id("rr")] = ft_strdup("rr");
	names[cmd_id("rra")] = ft_strdup("rra");
	names[cmd_id("rrb")] = ft_strdup("rrb");
	names[cmd_id("rrr")] = ft_strdup("rrr");
	return (names);
}

int		cmd_id(char *name)
{
	int		i;
	int		id;

	i = 0;
	id = 0;
	if (!name)
		return (0);
	while (name[i])
	{
		if (name[i] == 's')
			id += 24;
		else if (name[i] == 'p')
			id += 20;
		else if (name[i] == 'r')
			id += 5;
		else if (name[i] == 'a')
			id += 1;
		else if (name[i] == 'b')
			id += 2;
		else
			id -= 50;
		i++;
	}
	return (id);
}

void	ps_free_names(char **names)
{
	free(names[cmd_id("sa")]);
	free(names[cmd_id("sb")]);
	free(names[cmd_id("ss")]);
	free(names[cmd_id("pa")]);
	free(names[cmd_id("pb")]);
	free(names[cmd_id("ra")]);
	free(names[cmd_id("rb")]);
	free(names[cmd_id("rr")]);
	free(names[cmd_id("rra")]);
	free(names[cmd_id("rrb")]);
	free(names[cmd_id("rrr")]);
	free(names);
}
