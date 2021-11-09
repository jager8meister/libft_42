/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:48:38 by tsidney           #+#    #+#             */
/*   Updated: 2020/11/17 01:06:00 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*result;
	char	symbol;

	result = (char *)s;
	symbol = (char)c;
	while (*result && !(*result == symbol))
		result++;
	if (*result == symbol)
		return (result);
	return (NULL);
}
