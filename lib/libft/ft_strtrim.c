/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:38:17 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/27 17:49:19 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	define_size(char const *s, size_t *start)
{
	size_t	end;

	*start = 0;
	while (s[*start] == ' ' || s[*start] == '\n' || s[*start] == '\t')
		*start += 1;
	end = ft_strlen(s) - 1;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end > 0)
		end--;
	return (*start == ft_strlen(s) ? 0 : end - *start + 1);
}

char			*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	size;
	char	*newstr;

	if (!s)
		return (NULL);
	size = define_size(s, &start);
	if (!(newstr = ft_strnew(size)))
		return (NULL);
	ft_memcpy(newstr, &s[start], size);
	return (newstr);
}
