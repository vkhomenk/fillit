/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:43:31 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/28 18:38:04 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
	c == '\v' || c == '\f' || c == '\r');
}

static int	ind(char c, const char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int			ft_atoi_base(const char *nptr, int base)
{
	char	basestr[17];
	int		result;
	int		negative;

	if (!nptr)
		return (0);
	result = 0;
	ft_strcpy(basestr, "0123456789ABCDEF");
	if (base < 2)
		return (0);
	while (is_whitespace(*nptr))
		nptr++;
	negative = *nptr == '-';
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (ind(*nptr, basestr) < base)
		result = result * base - ind(*nptr++, basestr);
	return (negative ? result : -result);
}
