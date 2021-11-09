/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:46:11 by tsidney           #+#    #+#             */
/*   Updated: 2020/11/17 01:04:23 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	symbol;
	unsigned char	*new_dst;
	unsigned char	*new_src;

	symbol = (unsigned char)c;
	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	while (n--)
	{
		*new_dst++ = *new_src++;
		if (*(new_dst - 1) == symbol)
			return (new_dst);
	}
	return (NULL);
}
