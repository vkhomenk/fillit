/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:56:06 by vkhomenk          #+#    #+#             */
/*   Updated: 2019/01/17 17:43:29 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newelem;

	if (!(newelem = (t_list*)malloc(sizeof(*newelem))))
		return (NULL);
	if (!content)
	{
		newelem->content = NULL;
		newelem->content_size = 0;
	}
	else
	{
		if (!(newelem->content = malloc(content_size)))
		{
			free(newelem);
			return (NULL);
		}
		ft_memcpy(newelem->content, content, content_size);
		newelem->content_size = content_size;
	}
	newelem->next = NULL;
	return (newelem);
}
