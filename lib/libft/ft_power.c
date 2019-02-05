/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:08:24 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/27 22:42:48 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_power(int nb, int power)
{
	int			j;
	long long	res;
	long long	tmp;

	if (power == 0)
		return (1);
	res = 1;
	j = 0;
	tmp = (long long)nb;
	while (j++ < power)
	{
		res = res * tmp;
		if (res > 2147483647 || res < -2147483648)
			return (0);
	}
	return (res);
}
