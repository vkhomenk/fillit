/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:55:33 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/27 22:41:08 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_nbrlen_base(long nbr, size_t base)
{
	int				count;
	unsigned int	sign;
	unsigned int	tmp;

	if (base < 2 || nbr == 0)
		return (base < 2 ? 0 : 1);
	count = nbr < 0;
	sign = nbr < 0 ? -1 : 1;
	tmp = (unsigned int)nbr * sign;
	while (tmp >= base)
	{
		tmp /= base;
		count++;
	}
	count++;
	return (count);
}
