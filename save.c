/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 12:22:22 by yaitalla          #+#    #+#             */
/*   Updated: 2015/10/30 17:42:19 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static t_arg		*create_arg(char *name, t_bool f)
{
	t_arg			*new;
	struct stat		st;

	new = (t_arg*)malloc(sizeof(t_arg));
	if (new)
	{
		new->name = ft_strdup(name);
		new->f = f;
		stat(name, &st);
		new->stat = get_stat(name, NULL);
		new->prev = NULL;
		new->next = NULL;
	}
	return (new);
}

static t_file		*create_file(t_dirent *file, char *path)
{
	t_file			*new;
	char			*new_path;

	new = (t_file *)malloc(sizeof(t_file));
	new_path = ft_memalloc(ft_strlen(path) + ft_strlen(file->d_name) + 2);
	ft_strcat(new_path, path);
	if (path[ft_strlen(path) - 1] != '/')
		ft_strcat(new_path, "/");
	ft_strcat(new_path, file->d_name);
	if (new)
	{
		new->name = ft_strdup(file->d_name);
		new->path = new_path;
		new->stat = get_stat(new_path, file);
		new->files = NULL;
		new->prev = NULL;
		new->next = NULL;
	}
	return (new);
}

void				push_file(t_file *dir, t_dirent *file)
{
	t_file			*new;
	t_file			*curr;
	t_file			*tmp;

	new = create_file(file, dir->path);
	if (dir->files == NULL)
		dir->files = new;
	else
	{
		tmp = dir->files;
		curr = NULL;
		while (tmp && ft_strcmp(file->d_name, tmp->name) > 0)
		{
			curr = tmp;
			tmp = tmp->next;
		}
		if (curr)
			curr->next = new;
		else
			dir->files = new;
		new->prev = curr;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
	}
}

static void			push_arg(char *name, t_ls *ls, t_bool f)
{
	t_arg			*arg;
	t_arg			*curr;
	t_arg			*tmp;

	arg = create_arg(name, f);
	if (ls->arg == NULL)
		ls->arg = arg;
	else
	{
		tmp = ls->arg;
		curr = NULL;
		while (tmp && ft_strcmp(name, tmp->name) > 0)
		{
			curr = tmp;
			tmp = tmp->next;
		}
		if (curr)
			curr->next = arg;
		else
			ls->arg = arg;
		arg->prev = curr;
		arg->next = tmp;
		if (tmp)
			tmp->prev = arg;
	}
}

void				get_arg(char *name, t_ls *ls)
{
	DIR				*d;

	d = opendir(name);
	if (d == NULL)
	{
		if (errno == ENOTDIR)
			push_arg(name, ls, 1);
		else if (errno == EACCES)
			push_arg(name, ls, 0);
		else
		{
			ft_putstr_fd("ft_ls: ", 2);
			ft_putstr_fd(name, 2);
			ft_putendl_fd(": No such file or directory", 2);
			ls->status = 1;
		}
	}
	else
		push_arg(name, ls, 0);
	if (d)
		closedir(d);
}
