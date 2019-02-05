/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:07:15 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/20 21:47:19 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;

	if (!s || !f)
		return (0);
	newstr = ft_strdup((const char *)s);
	if (!newstr)
		return (NULL);
	i = 0;
	while (newstr[i] != 0)
	{
		newstr[i] = f(newstr[i]);
		i++;
	}
	return (newstr);
}
