/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:48:49 by tsidney           #+#    #+#             */
/*   Updated: 2020/11/17 01:06:06 by tsidney          ###   ########.fr       */
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

char		*ft_strdup(const char *s1)
{
	size_t	i;
	char	*result;

	if ((result = new_string(ft_strlen(s1))))
	{
		i = 0;
		while (s1[i])
		{
			result[i] = s1[i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
