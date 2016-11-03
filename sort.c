/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 13:59:06 by yaitalla          #+#    #+#             */
/*   Updated: 2015/10/30 17:46:14 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void		swap_file(t_file *a, t_file *b, t_file *dir)
{
	b->prev = a->prev;
	a->prev = b;
	if (b->prev)
		b->prev->next = b;
	a->next = b->next;
	b->next = a;
	if (a->next)
		a->next->prev = a;
	if (b->prev == NULL)
		dir->files = b;
}

static void		swap_arg(t_arg *a, t_arg *b, t_ls *ls)
{
	b->prev = a->prev;
	a->prev = b;
	if (b->prev)
		b->prev->next = b;
	a->next = b->next;
	b->next = a;
	if (a->next)
		a->next->prev = a;
	if (b->prev == NULL)
		ls->arg = b;
}

void			sort_file(t_file *dir, t_opt opt)
{
	t_file		*tmp;
	int			i;

	if (opt.t)
	{
		i = 0;
		while (i < file_size(dir->files))
		{
			tmp = dir->files;
			while (tmp && tmp->next)
			{
				if (tmp->stat->time < tmp->next->stat->time)
					swap_file(tmp, tmp->next, dir);
				else
					tmp = tmp->next;
			}
			i++;
		}
	}
	if (opt.r)
	{
		while (dir->files && dir->files->next)
			dir->files = dir->files->next;
	}
}

void			sort_arg(t_ls *ls)
{
	t_arg		*tmp;
	int			i;

	if (ls->opt.t)
	{
		i = 0;
		while (i < arg_size(ls->arg))
		{
			tmp = ls->arg;
			while (tmp && tmp->next)
			{
				if (tmp->stat->time < tmp->next->stat->time)
					swap_arg(tmp, tmp->next, ls);
				else
					tmp = tmp->next;
			}
			i++;
		}
	}
	if (ls->opt.r)
	{
		while (ls->arg && ls->arg->next)
			ls->arg = ls->arg->next;
	}
}

quad_t			sizer(quad_t n)
{
	quad_t		i;

	i = 1;
	if (n == 0)
		return (0);
	while (n > 9 || n < -9)
	{
		n /= 10;
		i++;
	}
	return (i);
}
