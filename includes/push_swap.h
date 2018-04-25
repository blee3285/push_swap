/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:43:55 by blee              #+#    #+#             */
/*   Updated: 2018/04/24 21:17:15 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/includes/libft.h"

typedef struct		s_num
{
	int				num;
	struct s_num	*next;
}					t_num;

//checker
t_num	*ps_newlst(int num);
void	ps_addlst(t_num *lst, t_num *new);
void	ps_buildlst(t_num **lst, char *num);

#endif
