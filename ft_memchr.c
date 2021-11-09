/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:46:23 by tsidney           #+#    #+#             */
/*   Updated: 2020/11/17 01:04:29 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr;
	unsigned char symbol;

	ptr = (unsigned char *)s;
	symbol = (unsigned char)c;
	while (n--)
	{
		if (*ptr == symbol)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
