/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:55:25 by yaitalla          #+#    #+#             */
/*   Updated: 2015/04/24 15:00:43 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **lst, void (*del)(void *, size_t))
{
	if (!lst || !*lst)
		return ;
	if (del)
		del((*lst)->content, (*lst)->content_size);
	else
		free((*lst)->content);
	(*lst)->content = NULL;
	ft_memdel((void **)lst);
}
