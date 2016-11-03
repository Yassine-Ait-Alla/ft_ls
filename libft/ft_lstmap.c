/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:10:47 by yaitalla          #+#    #+#             */
/*   Updated: 2015/01/04 23:43:24 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*src;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	new = (*f)(lst);
	temp = new;
	src = new;
	lst = lst->next;
	while (lst)
	{
		new = f(lst);
		if (new == NULL)
			return (NULL);
		temp->next = new;
		temp = new;
		lst = lst->next;
	}
	new->next = NULL;
	return (src);
}
