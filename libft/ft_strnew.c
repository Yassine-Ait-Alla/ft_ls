/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:56:48 by yaitalla          #+#    #+#             */
/*   Updated: 2015/01/05 01:50:53 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*str;

	str = (char *)ft_memalloc((size + 1));
	if (!str)
		return (NULL);
	ft_bzero((void *)str, size + 1);
	return (str);
}
