/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:40:41 by tsidney           #+#    #+#             */
/*   Updated: 2020/11/17 01:00:51 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	return (c == '\t' ||
			c == '\n' ||
			c == '\v' ||
			c == '\f' ||
			c == '\r' ||
			c == ' ');
}

static int	minus_check(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static int	border_error(long long x, int sign)
{
	long long	border;

	border = 2147483647;
	if ((x > border) && sign == 1)
		return (-1);
	if ((x > border + 1) && sign == -1)
		return (0);
	return (1);
}

int			ft_atoi(const char *str)
{
	long long	result;
	size_t		i;
	int			sign;

	result = 0;
	i = 0;
	while (is_space(str[i]))
		i++;
	sign = minus_check(str[i]);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (border_error(result, sign) != 1)
			return (border_error(result, sign));
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}
