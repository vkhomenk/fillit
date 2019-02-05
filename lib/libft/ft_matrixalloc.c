/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixalloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:04:35 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/12/24 16:38:17 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	**ft_matrixalloc(unsigned int row, unsigned int col, size_t size)
{
	void	**res;
	int		i;

	if (!(res = ft_memalloc(sizeof(void**) * row)))
		return (NULL);
	i = 0;
	while ((unsigned int)i < row)
		if (!(res[i++] = (char*)ft_memalloc(size * col)))
		{
			while (--i >= 0)
				ft_memdel(res[i]);
			ft_memdel(res);
			return (NULL);
		}
	return (res);
}
