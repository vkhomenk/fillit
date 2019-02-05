/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 20:17:57 by vkhomenk          #+#    #+#             */
/*   Updated: 2019/02/05 19:37:02 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <libft.h>
# define IFRET(x, y) if (x) return (y);
# define IFPLUS(x, y) if (x) ++y;

typedef struct	s_mino
{
	char		symb;
	int			height;
	int			width;
	int			x[4];
	int			y[4];
}				t_mino;

t_mino			*read_file(int fd, int *amount);
void			move_coordinates(int min_max[2][2], int *x, int *y);
void			fillit(int amount, t_mino *mino);
void			print_map(char **mino, int size);

#endif
