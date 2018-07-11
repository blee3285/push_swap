/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:20:26 by blee              #+#    #+#             */
/*   Updated: 2018/07/10 16:52:16 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_ten_digit(char *num, int neg)
{
	int		test;

	if (num[0] > '2')
		return (0);
	test = ft_atoi(&num[1]);
	if (neg)
	{
		if (test > 147483648)
			return (0);
	}
	else if (test > 147483647)
		return (0);
	return (1);
}

int		ps_numlen(char *num)
{
	int		i;

	i = 0;
	while (num[i] && ft_isdigit(num[i]))
		i++;
	return (i);
}

int		int_max_check(char *num)
{
	int		i;
	int		neg;
	int		len;

	i = 0;
	neg = 0;
	len = 0;
	if (num[0] == '-')
	{
		i++;
		neg = 1;
	}
	len = ps_numlen(&num[i]);
	if (len > 10)
		return (0);
	else if (len < 10)
		return (1);
	else if (check_ten_digit(&num[i], neg))
		return (1);
	return (0);
}
