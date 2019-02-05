/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:55:01 by vkhomenk          #+#    #+#             */
/*   Updated: 2019/02/03 18:49:45 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		main(int ac, char **av)
{
	t_mino	*mino;
	int		fd;
	int		amount;

	if (ac != 2)
	{
		ft_putstr("./fillit: wrong number of parameters\n\
Try \'./fillit [input_file]\' for proper work.\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || !(mino = read_file(fd, &amount)))
		ft_putstr("error\n");
	else
		fillit(amount, mino);
	ft_memdel((void*)&mino);
	close(fd);
	return (0);
}
