/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:17:00 by blee              #+#    #+#             */
/*   Updated: 2018/05/05 16:08:36 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

swapf	*ps_init_cmds()
{
	swapf	*cmds;

	cmds = (swapf*)malloc(sizeof(swapf*) * 400);
	if (!cmds)
		return (NULL);
	ft_bzero(cmds, sizeof(swapf*) * 400);
	cmds['s' + 'a'] = &ps_sa;
	cmds['s' + 'b'] = &ps_sb;
	cmds['s' + 's'] = &ps_ss;
	cmds['p' + 'a'] = &ps_pa;
	cmds['p' + 'b'] = &ps_pb;
	cmds['r' + 'a'] = &ps_ra;
	cmds['r' + 'b'] = &ps_rb;
	cmds['r' + 'r'] = &ps_rr;
	cmds['r' + 'r' + 'a'] = &ps_rra;
	cmds['r' + 'r' + 'b'] = &ps_rrb;
	cmds['r' + 'r' + 'r'] = &ps_rrr;
	return (cmds);
}

char	**ps_cmd_names()
{
	char	**names;

	names = (char**)malloc(sizeof(char*) * 400);
	if (!names)
		return (NULL);
	ft_bzero(names, sizeof(char*) * 400);
	names['s' + 'a'] = ft_strdup("sa");
	names['s' + 'b'] = ft_strdup("sb");
	names['s' + 's'] = ft_strdup("ss");
	names['p' + 'a'] = ft_strdup("pa");
	names['p' + 'b'] = ft_strdup("pb");
	names['r' + 'a'] = ft_strdup("ra");
	names['r' + 'b'] = ft_strdup("rb");
	names['r' + 'r'] = ft_strdup("rr");
	names['r' + 'r' + 'a'] = ft_strdup("rra");
	names['r' + 'r' + 'b'] = ft_strdup("rrb");
	names['r' + 'r' + 'r'] = ft_strdup("rrr");
	return (names);
}

int		cmd_id(char* name)
{
	int		i;
	int		id;

	i = 0;
	id = 0;
	if (!name)
		return (0);
	while (name[i])
	{
		id += name[i];
		i++;
	}
	return (id);
}

void	ps_free_names(char **names)
{
	free(names['s' + 'a']);
	free(names['s' + 'b']);
	free(names['s' + 's']);
	free(names['p' + 'a']);
	free(names['p' + 'b']);
	free(names['r' + 'a']);
	free(names['r' + 'b']);
	free(names['r' + 'r']);
	free(names['r' + 'r' + 'a']);
	free(names['r' + 'r' + 'b']);
	free(names['r' + 'r' + 'b']);
	free(names['r' + 'r' + 'r']);
	free(names);
}
