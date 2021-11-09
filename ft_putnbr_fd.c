/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:47:53 by tsidney           #+#    #+#             */
/*   Updated: 2020/11/17 01:05:28 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	abs_function(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void		ft_putnbr_fd(int n, int fd)
{
	char	result[50];
	int		is_negative;
	int		length;

	is_negative = (n < 0);
	ft_bzero(result, 50);
	if (n == 0)
		result[0] = '0';
	length = 0;
	while (n != 0)
	{
		result[length++] = '0' + abs_function(n % 10);
		n /= 10;
	}
	if (is_negative)
		result[length] = '-';
	else if (length > 0)
		length--;
	while (length >= 0)
		write(fd, &result[length--], 1);
}
