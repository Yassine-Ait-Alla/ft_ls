/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:42:54 by yaitalla          #+#    #+#             */
/*   Updated: 2015/01/28 08:32:57 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	int		ret;

	ret = (n < 0) ? -n : n;
	return (ret);
}

void		ft_putnbr(int n)
{
	if (n < 0)
		write(1, "-", 1);
	if (n >= 10 || n <= -10)
	{
		ft_putnbr(ft_abs(n / 10));
		ft_putnbr(ft_abs(n % 10));
	}
	else
		ft_putchar(ft_abs(n) + '0');
}
