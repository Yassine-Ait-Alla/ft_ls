/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 13:57:59 by yaitalla          #+#    #+#             */
/*   Updated: 2015/10/30 17:45:42 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int				arg_size(t_arg *arg)
{
	int			i;

	i = 0;
	while (arg)
	{
		arg = arg->next;
		i++;
	}
	return (i);
}

int				file_size(t_file *file)
{
	int			i;

	i = 0;
	while (file)
	{
		file = file->next;
		i++;
	}
	return (i);
}

static void		init_opt(t_ls *ls)
{
	ls->opt.a = 0;
	ls->opt.r = 0;
	ls->opt.t = 0;
	ls->opt.rec = 0;
	ls->opt.l = 0;
}

static void		manage_opt(char *arg, t_ls *ls)
{
	int			i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] == 'a')
			ls->opt.a = 1;
		else if (arg[i] == 'r')
			ls->opt.r = 1;
		else if (arg[i] == 't')
			ls->opt.t = 1;
		else if (arg[i] == 'R')
			ls->opt.rec = 1;
		else if (arg[i] == 'l')
			ls->opt.l = 1;
		else
		{
			ft_putstr_fd("ft_ls: illegal option -- ", 2);
			ft_putchar_fd(arg[i], 2);
			ft_putendl_fd("\nusage: ft_ls [-Ralrt] [file ...]", 2);
			free_ls(ls);
			exit(1);
		}
		i++;
	}
}

int				get_opt(char **av, t_ls *ls)
{
	int			i;

	i = 1;
	init_opt(ls);
	while (av[i] && av[i][0] == '-' && av[i][1])
	{
		manage_opt(av[i], ls);
		i++;
	}
	return (i);
}
