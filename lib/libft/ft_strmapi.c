/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:57:21 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/27 18:29:02 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		newstr[i] = f((unsigned int)i, newstr[i]);
		i++;
	}
	return (newstr);
}
