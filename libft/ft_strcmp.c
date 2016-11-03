/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:41:00 by yaitalla          #+#    #+#             */
/*   Updated: 2015/08/06 19:33:10 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	unsigned char		c1;
	unsigned char		c2;

	c1 = (unsigned char)*s1++;
	c2 = (unsigned char)*s2++;
	if (c1 == '\0')
		return (c1 - c2);
	while (c1 == c2)
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 == '\0')
			return (c1 - c2);
	}
	return (c1 - c2);
}
