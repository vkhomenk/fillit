/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:49:29 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/24 15:04:59 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_intiter(int *tab, unsigned int length, void (*f)(int *))
{
	unsigned int	i;

	if (!f)
		return ;
	i = 0;
	while (i < length)
		f(&tab[i++]);
}
