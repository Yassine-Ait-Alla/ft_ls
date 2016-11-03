/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:15:34 by yaitalla          #+#    #+#             */
/*   Updated: 2015/01/04 23:59:38 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	lengh;
	char	*new;

	lengh = ft_strlen(s);
	if (start > lengh || len > lengh)
		return (NULL);
	if (start + len > lengh)
		return (NULL);
	if (!(new = ft_strnew(len)))
		return (NULL);
	new = ft_strncpy(new, s + start, len);
	new[len] = '\0';
	return (new);
}
