/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 21:18:01 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/20 21:51:09 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*found;

	found = (char*)haystack;
	if (needle[0] == 0)
		return (found);
	i = 0;
	while (haystack[i] != 0)
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (i + j >= len)
				break ;
			if (needle[j + 1] == 0)
			{
				found = (char*)&haystack[i];
				return (found);
			}
			j++;
		}
		i++;
	}
	return (0);
}
