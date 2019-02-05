/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:44:47 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/20 23:35:02 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] - str2[i])
		{
			if (str1[i] < 32 && str2[i] < 32)
				return (str2[i] - str1[i]);
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}
