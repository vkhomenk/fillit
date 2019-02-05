/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:46:31 by vkhomenk          #+#    #+#             */
/*   Updated: 2018/11/20 23:34:00 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int l1;
	int l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	return (ft_strncmp(s1, s2, (l1 > l2 ? l1 : l2) + 1));
}
