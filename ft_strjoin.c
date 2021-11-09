/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:49:06 by tsidney           #+#    #+#             */
/*   Updated: 2020/11/17 01:06:13 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*empty_string(size_t size)
{
	void *result;

	if ((result = malloc(size)))
		ft_bzero(result, size);
	return (result);
}

static char	*new_string(size_t size)
{
	return ((char *)empty_string(sizeof(char) * (size + 1)));
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 && s2)
		return (NULL);
	result = new_string(ft_strlen(s1) + ft_strlen(s2));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		result[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		result[j++] = s2[i];
		i++;
	}
	result[j] = 0;
	return (result);
}
