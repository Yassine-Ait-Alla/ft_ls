/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:45:32 by yaitalla          #+#    #+#             */
/*   Updated: 2014/11/11 15:31:55 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		i;

	if (!src && !dst)
		return (NULL);
	i = ft_strlen(src);
	if (i < n)
	{
		dst = ft_memcpy(dst, src, i);
		while (i < n)
		{
			dst[i] = 0;
			i++;
		}
	}
	else
		dst = ft_memcpy(dst, src, n);
	return (dst);
}
