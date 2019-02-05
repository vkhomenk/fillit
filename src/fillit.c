/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:28:54 by vkhomenk          #+#    #+#             */
/*   Updated: 2019/02/05 19:37:24 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void	correct_map(char **map, int i, int j, t_mino *m)
{
	int		k;

	k = -1;
	while (++k < 4)
		map[i + m->x[k]][j + m->y[k]] = m->symb > 0 ? m->symb : '.';
}

static int	fit_mino(char **map, int i, int j, t_mino *m)
{
	int		k;

	k = -1;
	while (++k < 4)
	{
		if (map[i + m->x[k]][j + m->y[k]] != '.')
			return (0);
	}
	correct_map(map, i, j, m);
	return (1);
}

static int	fill(char **map, int size, t_mino *m)
{
	int		i;
	int		j;

	if (!m->symb)
		return (1);
	i = -1;
	while (++i < size - m->height + 1)
	{
		j = -1;
		while (++j < size - m->width + 1)
		{
			if (fit_mino(map, i, j, m))
			{
				if (fill(map, size, m + 1))
					return (1);
				m->symb *= -1;
				correct_map(map, i, j, m);
				m->symb *= -1;
			}
		}
	}
	return (0);
}

static char	**get_map(int size)
{
	int		i;
	char	**map;

	if (!(map = (char**)ft_matrixalloc(size, size + 1, 1)))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		ft_memset(map[i], '.', size);
		map[i][size] = 0;
	}
	return (map);
}

void		fillit(int amount, t_mino *mino)
{
	int		size;
	char	**map;

	size = 2;
	while (size * size < amount * 4)
		size++;
	if (!(map = get_map(size)))
		return ;
	while (!fill(map, size, mino))
	{
		ft_matrixdel((void*)&map, size);
		if (!(map = get_map(++size)))
			return ;
	}
	print_map(map, size);
	ft_matrixdel((void*)&map, size);
}
