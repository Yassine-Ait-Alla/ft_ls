/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:18:18 by yaitalla          #+#    #+#             */
/*   Updated: 2015/08/17 19:42:43 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		lenght;

	i = 0;
	while (i < size)
	{
		if (dst[i] == '\0')
			break ;
		i++;
	}
	lenght = i + ft_strlen(src);
	k = size - i - 1;
	if (i != size)
	{
		j = 0;
		while (src[j] && j < k)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	return (lenght);
}
