/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:56:07 by tsidney           #+#    #+#             */
/*   Updated: 2020/11/17 01:07:35 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*result;
	size_t	needle_length;
	size_t	j;
	size_t	i;

	result = (char *)haystack;
	needle_length = ft_strlen(needle);
	if (needle_length == 0)
		return (result);
	if (ft_strlen(haystack) < needle_length || len < needle_length)
		return (NULL);
	i = 0;
	while (result[i] && i <= len - needle_length)
	{
		j = 0;
		while (needle[j] && needle[j] == result[i + j])
			j++;
		if (j == needle_length)
			return (&result[i]);
		i++;
	}
	return (NULL);
}
