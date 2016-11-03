/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:19:33 by yaitalla          #+#    #+#             */
/*   Updated: 2014/12/24 20:00:24 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	len_s2;

	len_s2 = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	while (*s1 && len_s2)
	{
		if (!ft_memcmp(s1++, s2, len_s2))
			return ((char *)s1 - 1);
	}
	return (NULL);
}
