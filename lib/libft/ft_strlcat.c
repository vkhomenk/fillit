/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:29:43 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/20 17:44:58 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	sum;

	sum = ft_strlen(dst) + ft_strlen(src);
	if (dstsize > ft_strlen(dst))
		ft_strncat(dst, src, dstsize - ft_strlen(dst) - 1);
	else
		sum = ft_strlen(src) + dstsize;
	return (sum);
}
