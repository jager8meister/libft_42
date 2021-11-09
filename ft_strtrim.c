/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:50:47 by tsidney           #+#    #+#             */
/*   Updated: 2020/11/17 01:07:51 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set_check(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

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

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && char_in_set_check(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && char_in_set_check(s1[end - 1], set))
		end--;
	trimmed_str = new_string(end - start);
	if (!trimmed_str)
		return (NULL);
	i = 0;
	while (start < end)
		trimmed_str[i++] = s1[start++];
	trimmed_str[i] = 0;
	return (trimmed_str);
}
