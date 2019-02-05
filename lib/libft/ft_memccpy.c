/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:15:31 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/15 14:17:18 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *strsrc;
	char *strdest;
	char ch;

	ch = c;
	strsrc = (char*)src;
	strdest = (char*)dest;
	while (n > 0 && *strsrc != ch)
	{
		n--;
		*strdest++ = *strsrc++;
	}
	if (n > 0)
	{
		*strdest++ = *strsrc++;
		return ((void*)strdest);
	}
	else
		return (0);
}
