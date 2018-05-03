/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:17:00 by blee              #+#    #+#             */
/*   Updated: 2018/05/02 18:33:59 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

swapf		*init_cmds()
{
	swapf	*cmds;

	cmds = (swapf*)malloc(sizeof(swapf*) * 400);
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
