/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:49:42 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/27 22:38:35 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	*help(long *num, int base, int *i, int *count)
{
	char	*new;
	long	tmp;

	if (*num < 0)
	{
		*i = base == 10;
		(*num) *= -1;
	}
	tmp = *num;
	*count = (ft_nbrlen_base(tmp, base) + *i);
	if (!(new = ft_strnew(*count)))
		return (NULL);
	return (new);
}

char		*ft_itoa_base(int n, int base)
{
	char	basestr[17];
	char	*new;
	long	num;
	int		i;
	int		count;

	i = 0;
	count = 0;
	num = n;
	ft_strcpy(basestr, "0123456789ABCDEF");
	if (base < 2 || !(new = help(&num, base, &i, &count)))
		return (NULL);
	if (i > 0)
		new[0] = '-';
	new[count] = 0;
	while (num >= base)
	{
		new[--count] = basestr[num % base];
		num /= base;
	}
	new[i] = basestr[num % base];
	return (new);
}
