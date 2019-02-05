/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:27:03 by vkhomenk          #+#    #+#             */
/*   Updated: 2019/02/01 04:39:28 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_matrixdel(void ***matr, unsigned int row)
{
	unsigned int	i;
	char			**m;

	if (!matr)
		return ;
	m = (char**)*matr;
	i = 0;
	while (i < row)
		ft_memdel((void*)&m[i++]);
	ft_memdel((void*)matr);
}
