/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:10:22 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/27 17:39:53 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_itoa(int n)
{
	unsigned int	i;
	int				len;
	char			*str;

	len = ft_nbrlen(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	i = n;
	if (n < 0)
		i = n * -1;
	while (len)
	{
		str[--len] = i % 10 + 48;
		i /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
