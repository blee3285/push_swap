/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:28:35 by blee              #+#    #+#             */
/*   Updated: 2018/07/06 19:53:44 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_other(t_num **lst_a, t_num **lst_b, int min, int max, char ab)
{
	int	mid;
	int	i;

	mid = (min + max + 1) / 2;
	//ft_printf("Min: %d Max: %d Mid: %d\n", min, max, mid);
	i = min;
	if (ab == 'a')
		while ((i++ <= max) && (*lst_a))
		{
			if ((*lst_a)->order < mid)
				ps_pb(lst_a, lst_b);
			else
				ps_ra(lst_a, lst_b);
		}
	else if (ab == 'b')
		while ((i++ <= max) && (*lst_b))
		{
			if ((*lst_b)->order >= mid)
				ps_pa(lst_a, lst_b);
			else
				ps_rb(lst_a, lst_b);
		}
	//ft_printf("Pushing done\n");
}

void	rot_back(t_num **lst_a, t_num **lst_b, int len, char ab)
{
	if (ab == 'a')
		while (len--)
			ps_rra(lst_a, lst_b);
	else if (ab == 'b')
		while (len--)
			ps_rrb(lst_a, lst_b);
}

void	quick_sort_a(t_num **lst_a, t_num **lst_b, int min, int max)
{
	int		len;
	int		mid;

	len = max - min + 1;
	mid = (max + min + 1) / 2;
	if (len < 2)
		return ;
	else if (len == 2)
	{
		if ((*lst_a)->order > (*lst_a)->next->order)
			ps_sa(lst_a, lst_b);
		return ;
	}
	push_to_other(lst_a, lst_b, min, max, 'a');
	rot_back(lst_a, lst_b, (max - mid + 1), 'a');
	//print_lst(*lst_a);
	//ft_putchar('\n');
	//print_lst(*lst_b);
	//ft_putchar('\n');
	quick_sort_a(lst_a, lst_b, mid, max);
	quick_sort_b(lst_a, lst_b, min, (mid - 1));
}

void	quick_sort_b(t_num **lst_a, t_num **lst_b, int min, int max)
{
	int		len;
	int		mid;

	len = max - min + 1;
	mid = (max + min + 1) / 2;
	if (len < 2)
	{
		ps_pa(lst_a, lst_b);
		return ;
	}
	else if (len == 2)
	{
		if ((*lst_b)->order < (*lst_b)->next->order)
			ps_sb(lst_a, lst_b);
		ps_pa(lst_a, lst_b);
		ps_pa(lst_a, lst_b);
		return ;
	}
	push_to_other(lst_a, lst_b, min, max, 'b');
	rot_back(lst_a, lst_b, (mid - min), 'b');
	//print_lst(*lst_a);
	//ft_putchar('\n');
	//print_lst(*lst_b);
	//ft_putchar('\n');
	quick_sort_a(lst_a, lst_b, mid, max);
	quick_sort_b(lst_a, lst_b, min, (mid - 1));
}

void	ps_big_sort(t_num **lst_a, t_num **lst_b, int min, int max)
{
	int		len;
	int		mid;

	len = max - min + 1;
	mid = (max + min + 1) / 2;
	if (len < 2)
		return ;
	else if (len == 2)
	{
		if ((*lst_a)->order > (*lst_a)->next->order)
			ps_sa(lst_a, lst_b);
		return ;
	}
	push_to_other(lst_a, lst_b, min, max, 'a');
	//print_lst(*lst_a);
	//ft_putchar('\n');
	//print_lst(*lst_b);
	//ft_putchar('\n');
	ps_big_sort(lst_a, lst_b, mid, max);
	quick_sort_b(lst_a, lst_b, min, (mid - 1));
}
