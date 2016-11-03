/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 13:51:30 by yaitalla          #+#    #+#             */
/*   Updated: 2015/04/24 15:01:06 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **lst, void (*del)(void *, size_t))
{
	if (!lst || !*lst)
		return ;
	if ((*lst)->next)
		ft_lstdel(&(*lst)->next, del);
	ft_lstdelone(lst, del);
}
