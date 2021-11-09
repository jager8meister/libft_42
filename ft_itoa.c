/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:42:52 by tsidney           #+#    #+#             */
/*   Updated: 2020/11/06 15:42:54 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		number_length(int number, int minus)
{
	int length;

	length = 1;
	while (number /= 10)
		length++;
	return (length + minus);
}

static void		*empty_string(size_t size)
{
	void *result;

	if ((result = malloc(size)))
		ft_bzero(result, size);
	return (result);
}

static char		*new_string(size_t size)
{
	return ((char *)empty_string(sizeof(char) * (size + 1)));
}

static int		minus_check(int x)
{
	if (x < 0)
		return (1);
	return (0);
}

char			*ft_itoa(int n)
{
	char	*result;
	int		numlength;
	int		minus;
	int		digit;
	int		abs;

	minus = minus_check(n);
	numlength = number_length(n, minus);
	if ((result = new_string(numlength)))
	{
		result[numlength--] = '\0';
		while (numlength >= minus)
		{
			digit = n % 10;
			abs = digit;
			if (minus_check(digit))
				abs = -digit;
			result[numlength--] = abs + '0';
			n /= 10;
		}
		if (minus)
			result[0] = '-';
	}
	return (result);
}
