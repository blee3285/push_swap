/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:22:44 by blee              #+#    #+#             */
/*   Updated: 2018/04/27 16:38:09 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "../libft/includes/libft.h"

typedef struct		s_num
{
	int				num;
	struct s_num	*next;
}					t_num;

t_num	*ps_newlst(int num);
void	ps_addlst(t_num *lst, t_num *new);
void	ps_buildlst(t_num **lst, char *num);

#endif
