/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 13:50:57 by yaitalla          #+#    #+#             */
/*   Updated: 2015/10/30 17:17:15 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static t_file	*init_dir(char *name, char *path)
{
	t_file		*dir;

	dir = (t_file*)malloc(sizeof(t_file));
	if (dir)
	{
		dir->name = ft_strdup(name);
		dir->path = ft_strdup(path);
		dir->stat = NULL;
		dir->files = NULL;
		dir->prev = NULL;
		dir->next = NULL;
	}
	return (dir);
}

static DIR		*get_dir(t_file *dir, t_ls *ls)
{
	DIR			*d;

	d = opendir(dir->path);
	if (d == NULL)
	{
		if (errno != ENOTDIR)
		{
			ft_putstr_fd("ft_ls: ", 2);
			ft_putstr_fd(dir->name, 2);
			ft_putendl_fd(": Permission denied", 2);
			ls->status = 1;
		}
	}
	return (d);
}

void			ft_ls(char *name, char *path, t_ls *ls)
{
	t_file		*dir;
	t_file		*tmp;
	DIR			*d;
	t_dirent	*file;

	dir = init_dir(name, path);
	if ((d = get_dir(dir, ls)) != NULL)
	{
		while ((file = readdir(d)))
			push_file(dir, file);
		closedir(d);
		sort_file(dir, ls->opt);
		ft_display(dir, ls);
		if (ls->opt.rec)
		{
			tmp = dir->files;
			while (tmp)
			{
				if (ft_strcmp(tmp->name, ".") && ft_strcmp(tmp->name, ".."))
					ft_ls(tmp->name, tmp->path, ls);
				tmp = ls->opt.r ? tmp->prev : tmp->next;
			}
		}
	}
	free_dir(dir, ls->opt);
}
