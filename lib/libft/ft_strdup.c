/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:28:18 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/20 21:44:26 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	str = (char*)malloc(ft_strlen(s) + 1);
	if (str == 0)
		return (0);
	ft_strcpy(str, s);
	return (str);
}
