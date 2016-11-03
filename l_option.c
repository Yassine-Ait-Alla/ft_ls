/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_option.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 14:08:56 by yaitalla          #+#    #+#             */
/*   Updated: 2015/10/30 18:04:31 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void		dev_sizer(t_file *file, t_max max)
{
	if (file->stat->minor || file->stat->major)
	{
		ft_putchars(' ', max.major - ft_countnbr(file->stat->major) + 1);
		ft_putnbr(file->stat->major);
		ft_putchar(',');
		ft_putchars(' ', max.minor - ft_countnbr(file->stat->minor) + 1);
		ft_putnbr(file->stat->minor);
	}
	else
	{
		if (max.major)
			ft_putchars(' ', max.major + max.minor -
						ft_countnbr(file->stat->size) + 2);
		else
			ft_putchars(' ', max.size - ft_countnbr(file->stat->size) + 1);
		if (max.major)
			ft_putchar(' ');
		ft_putnbr(file->stat->size);
	}
}

void			l_display(t_file *file, t_max max)
{
	ft_putstr(file->stat->mode);
	ft_putchars(' ', max.lnk - ft_countnbr(file->stat->lnk) + 1);
	ft_putnbr(file->stat->lnk);
	ft_putchar(' ');
	ft_putstr(file->stat->usr);
	ft_putchars(' ', max.usr - ft_strlen(file->stat->usr) + 1);
	ft_putstr(file->stat->grp);
	ft_putchars(' ', max.grp - ft_strlen(file->stat->grp));
	dev_sizer(file, max);
	ft_putchar(' ');
	ft_putstr(file->stat->mtime);
	ft_putchar(' ');
	ft_putstr(file->name);
	if (file->stat->lnk_name[0])
	{
		ft_putstr(" -> ");
		ft_putstr(file->stat->lnk_name);
	}
	ft_putchar('\n');
}

void			init_len(t_max *max)
{
	max->lnk = 0;
	max->usr = 0;
	max->grp = 0;
	max->minor = 0;
	max->major = 0;
	max->size = 0;
}

void			get_len(t_file *dir, t_max *max, t_opt opt)
{
	t_file		*tmp;

	tmp = dir->files;
	while (tmp)
	{
		if (!opt.a && tmp->name[0] == '.')
			tmp = opt.r ? tmp->prev : tmp->next;
		else
		{
			max->lnk = ft_countnbr(tmp->stat->lnk) > max->lnk ?
				ft_countnbr(tmp->stat->lnk) : max->lnk;
			max->usr = ft_strlen(tmp->stat->usr) > max->usr ?
				ft_strlen(tmp->stat->usr) : max->usr;
			max->grp = ft_strlen(tmp->stat->grp) > max->grp ?
				ft_strlen(tmp->stat->grp) : max->grp;
			max->minor = sizer(tmp->stat->minor) > max->minor ?
				sizer(tmp->stat->minor) : max->minor;
			max->major = sizer(tmp->stat->major) > max->major ?
				sizer(tmp->stat->major) : max->major;
			max->size = ft_countnbr(tmp->stat->size) > max->size ?
				ft_countnbr(tmp->stat->size) : max->size;
			tmp = opt.r ? tmp->prev : tmp->next;
		}
	}
}

void			total(t_file *dir, t_opt opt)
{
	quad_t		total;
	t_file		*tmp;

	total = 0;
	tmp = dir->files;
	while (tmp)
	{
		if (!opt.a && tmp->name[0] == '.')
			tmp = opt.r ? tmp->prev : tmp->next;
		else
		{
			total += tmp->stat->blocks;
			tmp = opt.r ? tmp->prev : tmp->next;
		}
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}
