/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchudik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:06:27 by mchudik           #+#    #+#             */
/*   Updated: 2019/02/01 18:19:58 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void		get_coordinates(char *str, int min_max[2][2], int *x, int *y)
{
	int		i;
	int		j;

	j = -1;
	i = -1;
	while (++i < 20)
	{
		if (str[i] == '#')
		{
			x[++j] = i / 5;
			y[j] = i % 5;
			if (i / 5 < min_max[0][0])
				min_max[0][0] = i / 5;
			if (i % 5 < min_max[0][1])
				min_max[0][1] = i % 5;
			if (i / 5 > min_max[1][0])
				min_max[1][0] = i / 5;
			if (i % 5 > min_max[1][1])
				min_max[1][1] = i % 5;
		}
	}
	move_coordinates(min_max, x, y);
}

static int		save_mino(t_mino *m, char *str, int num)
{
	int		min_max[2][2];

	min_max[0][0] = 3;
	min_max[0][1] = 3;
	min_max[1][0] = 0;
	min_max[1][1] = 0;
	get_coordinates(str, min_max, m->x, m->y);
	m->height = min_max[1][0] - min_max[0][0] + 1;
	m->width = min_max[1][1] - min_max[0][1] + 1;
	m->symb = num + 65;
	return (1);
}

static int		validation(char *str, int not_end, int connect)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (++i < 20)
	{
		if (i % 5 < 4)
		{
			IFRET(str[i] != '.' && str[i] != '#', 0);
			if (str[i] == '#')
			{
				IFRET(++count > 4, 0);
				IFPLUS(i > 4 && str[i - 5] == '#', connect);
				IFPLUS(i < 14 && str[i + 5] == '#', connect);
				IFPLUS(i < 19 && str[i + 1] == '#', connect);
				IFPLUS(i > 0 && str[i - 1] == '#', connect);
			}
		}
		else
			IFRET(str[i] != '\n', 0);
	}
	IFRET(not_end && str[20] != '\n', 0);
	return (connect == 6 || connect == 8);
}

static t_mino	*how_many_minos(int fd, char **str, int *amount)
{
	int		cr;
	t_mino	*res;

	if (!(*str = (char*)malloc(21 * 26 + 1)))
		return (NULL);
	cr = read(fd, *str, 21 * 26);
	*amount = cr / 21 + 1;
	if (cr % 21 != 20 ||
	!(res = (t_mino*)ft_memalloc(sizeof(t_mino) * *amount + 1)))
	{
		*amount = 0;
		return (NULL);
	}
	res[*amount].symb = 0;
	return (res);
}

t_mino			*read_file(int fd, int *amount)
{
	char	*str;
	t_mino	*mino;
	int		i;

	*amount = 0;
	mino = how_many_minos(fd, &str, amount);
	i = -1;
	while (++i < *amount)
	{
		if (!validation(&str[i * 21], i < *amount - 1, 0) ||
			!save_mino(&mino[i], &str[i * 21], i))
		{
			ft_memdel((void*)&mino);
			break ;
		}
	}
	ft_strdel(&str);
	return (mino);
}
