/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:17:00 by blee              #+#    #+#             */
/*   Updated: 2018/04/28 18:56:28 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*(*init_cmds()(t_num*, t_num*))
{
	void	*(*cmds)(t_num*, t_num*);

	cmds = (*(*void))malloc(sizeof(*void) * 400);
	ft_bzero(cmds, sizeof(*void) * 400);
	cmd['s' + 'a'] = &ps_sa;
	cmd['s' + 'b'] = &ps_sb;
	cmd['s' + 's'] = &ps_ss;

	return (cmd);
}
