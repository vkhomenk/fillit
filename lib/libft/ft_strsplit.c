/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:42:52 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/27 18:42:55 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	get_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			i += get_len(&s[i], c) - 1;
		}
		i++;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	**str;

	len = 0;
	if (!s || !(str = (char**)ft_memalloc(sizeof(char*) *
	(len = (count_words(s, c)) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = get_len(&s[i], c);
			if (!(str[j++] = ft_strsub(s, i, len)))
				return (NULL);
			i += len - 1;
		}
		i++;
	}
	return (str);
}
