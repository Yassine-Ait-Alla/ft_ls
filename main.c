/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 12:06:29 by yaitalla          #+#    #+#             */
/*   Updated: 2015/10/30 17:52:44 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int		init(t_ls *ls, int ac, char **av)
{
	int			i;

	ls->arg = NULL;
	i = get_opt(av, ls);
	ls->nb_dir = ac - i;
	ls->space = 0;
	ls->status = 0;
	return (i);
}

int				main(int ac, char **av)
{
	t_ls		*ls;
	t_arg		*tmp;
	int			i;

	ls = (t_ls *)malloc(sizeof(t_ls));
	i = init(ls, ac, av);
	if (!av[i])
		get_arg(".", ls);
	else
	{
		while (av[i])
			get_arg(av[i++], ls);
	}
	sort_arg(ls);
	display(ls->arg, ls->opt, &(ls->space));
	tmp = ls->arg;
	while (tmp)
	{
		if (!tmp->f)
			ft_ls(tmp->name, tmp->name, ls);
		tmp = ls->opt.r ? tmp->prev : tmp->next;
	}
	i = ls->status;
	free_ls(ls);
	return (i);
}
