/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/28 05:46:56 by yaitalla          #+#    #+#             */
/*   Updated: 2015/08/28 06:12:43 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			sig_catcher(int i)
{
	if (i == SIGCONT)
		signal(SIGCONT, sig_catcher);
	if (i == SIGINT)
		return ;
	else if (i == SIGTSTP)
		signal(SIGTSTP, SIG_DFL);
	else
		exit(0);
}

void				signaler(void)
{
	int				i;

	i = 1;
	while (i < 32)
	{
		signal(i, sig_catcher);
		i++;
	}
}
