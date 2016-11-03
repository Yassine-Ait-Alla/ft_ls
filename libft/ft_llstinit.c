/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llstinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 00:22:51 by yaitalla          #+#    #+#             */
/*   Updated: 2015/08/24 00:28:54 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llst			*llst_init(void)
{
	t_llst			*lst;

	lst = (t_llst *)malloc(sizeof(t_llst));
	lst->len = 0;
	lst->select = 0;
	lst->content = NULL;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}
