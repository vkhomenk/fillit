/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 03:30:24 by vkhomenk          #+#    #+#             */
/*   Updated: 2019/02/01 04:34:40 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	move_coordinates(int min_max[2][2], int *x, int *y)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		x[i] -= min_max[0][0];
		y[i] -= min_max[0][1];
	}
}

void	print_map(char **mino, int size)
{
	int i;

	i = -1;
	while (++i < size && mino[i])
		ft_putendl(mino[i]);
}
