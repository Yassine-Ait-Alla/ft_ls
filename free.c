/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 13:44:39 by yaitalla          #+#    #+#             */
/*   Updated: 2015/10/30 18:02:46 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void		free_stat(t_stat *stat)
{
	free(stat->mode);
	free(stat->usr);
	free(stat->grp);
	free(stat->mtime);
	free(stat->lnk_name);
	free(stat);
}

void			free_files(t_file *file, t_opt opt)
{
	t_file		*tmp;

	while (file)
	{
		tmp = file;
		if (tmp->name)
			free(tmp->name);
		if (tmp->path)
			free(tmp->path);
		if (file->stat)
			free_stat(file->stat);
		file = opt.r ? file->prev : file->next;
		free(tmp);
	}
}

void			free_dir(t_file *dir, t_opt opt)
{
	free(dir->name);
	free(dir->path);
	if (dir->files)
		free_files(dir->files, opt);
	free(dir);
}

static void		free_arg(t_arg *arg, t_opt opt)
{
	t_arg		*tmp;

	while (arg)
	{
		tmp = arg;
		if (tmp->name)
			free(tmp->name);
		if (tmp->stat)
			free_stat(tmp->stat);
		arg = opt.r ? arg->prev : arg->next;
		free(tmp);
	}
}

void			free_ls(t_ls *ls)
{
	if (ls->arg)
		free_arg(ls->arg, ls->opt);
	free(ls);
}
