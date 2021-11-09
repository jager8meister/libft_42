/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:48:24 by tsidney           #+#    #+#             */
/*   Updated: 2020/11/06 15:48:25 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	word_length(char const *s, char c)
{
	size_t	length;

	length = 0;
	while (*s && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}

static	size_t	amount_of_words(char const *s, char c)
{
	size_t	total;

	total = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		if (*s != c)
		{
			total++;
			s += word_length(s, c);
		}
	}
	return (total);
}

static	void	*free_all_splits(char **split, size_t elems)
{
	size_t	i;

	i = 0;
	while (i < elems)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(split =
		(char **)malloc((amount_of_words(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			if (!(split[i] = ft_substr((char *)s, 0, word_length(s, c))))
				return (free_all_splits(split, i));
			i++;
			s += word_length(s, c);
		}
	}
	split[i] = NULL;
	return (split);
}
