/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 15:02:41 by yaitalla          #+#    #+#             */
/*   Updated: 2014/11/11 15:31:18 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*dest;
	char		*source;

	dest = (char *)dst;
	source = (char *)src;
	while (n--)
	{
		if (*source == c)
		{
			*dest++ = *source++;
			return (dest);
		}
		*dest++ = *source++;
	}
	return (NULL);
}
