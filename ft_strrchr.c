/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:50:34 by tsidney           #+#    #+#             */
/*   Updated: 2020/11/17 01:07:43 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	char	symbol;

	result = (char *)s + ft_strlen(s);
	symbol = (char)c;
	while (result >= s)
	{
		if (*result == symbol)
			return (result);
		result--;
	}
	return (NULL);
}
