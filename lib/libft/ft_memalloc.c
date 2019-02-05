/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:33:44 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/20 21:35:29 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char *memory;

	memory = (char*)malloc(size);
	if (memory == 0)
		return (NULL);
	while (size-- > 0)
		memory[size] = 0;
	return (memory);
}
