/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:13:32 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/20 21:38:54 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (dest == src)
		return (NULL);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		i = n;
		while (i-- > 0)
			*((unsigned char*)dest + i) = *((unsigned char*)src + i);
	}
	return (dest);
}
