/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:02:19 by yaitalla          #+#    #+#             */
/*   Updated: 2015/10/30 18:05:29 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static t_file	*save(char *name)
{
	t_file		*new;

	new = (t_file*)malloc(sizeof(t_file));
	if (new)
	{
		new->name = ft_strdup(name);
		new->path = ft_strdup(name);
		new->stat = get_stat(name, NULL);
		new->files = NULL;
		new->prev = NULL;
		new->next = NULL;
	}
	return (new);
}

static void		file_sizer(t_arg *arg, t_max *max, t_opt opt)
{
	while (arg)
	{
		if (arg->f)
		{
			max->lnk = ft_countnbr(arg->stat->lnk) > max->lnk ?
				ft_countnbr(arg->stat->lnk) : max->lnk;
			max->usr = ft_strlen(arg->stat->usr) > max->usr ?
				ft_strlen(arg->stat->usr) : max->usr;
			max->grp = ft_strlen(arg->stat->grp) > max->grp ?
				ft_strlen(arg->stat->grp) : max->grp;
			max->minor = sizer(arg->stat->minor) > max->minor ?
				sizer(arg->stat->minor) : max->minor;
			max->major = sizer(arg->stat->major) > max->major ?
				sizer(arg->stat->major) : max->major;
			max->size = ft_countnbr(arg->stat->size) > max->size ?
				ft_countnbr(arg->stat->size) : max->size;
		}
		arg = opt.r ? arg->prev : arg->next;
	}
}

void			display(t_arg *arg, t_opt opt, t_bool *space)
{
	t_file		*file;
	t_max		len;

	init_len(&len);
	file_sizer(arg, &len, opt);
	while (arg)
	{
		if (arg->f)
		{
			if (opt.l)
			{
				file = save(arg->name);
				l_display(file, len);
				free_files(file, opt);
			}
			else
				ft_putendl(arg->name);
			*space = 1;
		}
		arg = opt.r ? arg->prev : arg->next;
	}
}

static void		ft_display_file(t_file *file, t_opt opt, t_max len)
{
	if (!opt.a && (file->name)[0] == '.')
		file = opt.r ? file->prev : file->next;
	else
	{
		if (opt.l)
			l_display(file, len);
		else
			ft_putendl(file->name);
		file = opt.r ? file->prev : file->next;
	}
}

void			ft_display(t_file *dir, t_ls *ls)
{
	t_file		*tmp;
	t_max		len;

	tmp = dir->files;
	if (ls->nb_dir > 1 || ls->opt.rec)
	{
		if (ls->space)
			ft_putchar('\n');
		ft_putstr(dir->path);
		ft_putendl(":");
	}
	if (ls->opt.l)
		total(dir, ls->opt);
	init_len(&len);
	get_len(dir, &len, ls->opt);
	while (tmp)
	{
		ft_display_file(tmp, ls->opt, len);
		tmp = ls->opt.r ? tmp->prev : tmp->next;
		ls->space = 1;
	}
}
