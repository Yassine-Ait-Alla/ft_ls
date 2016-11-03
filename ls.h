/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 11:29:17 by yaitalla          #+#    #+#             */
/*   Updated: 2015/10/30 18:06:06 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <time.h>
# include <errno.h>
# include <sys/types.h>
# include <pwd.h>
# include <sys/dirent.h>
# include <uuid/uuid.h>
# include <grp.h>
# include "libft/libft.h"
# include "colors.h"

typedef struct dirent	t_dirent;
typedef unsigned char	t_bool;

typedef struct			s_max
{
	unsigned int		lnk;
	unsigned int		usr;
	unsigned int		grp;
	unsigned int		minor;
	unsigned int		major;
	unsigned int		size;
}						t_max;

typedef struct			s_stat
{
	char				*mode;
	int					lnk;
	char				*usr;
	char				*grp;
	int					major;
	int					minor;
	off_t				size;
	char				*mtime;
	time_t				time;
	char				*lnk_name;
	quad_t				blocks;
}						t_stat;

typedef struct			s_opt
{
	int					a;
	int					r;
	int					t;
	int					rec;
	int					l;
}						t_opt;

typedef struct			s_file
{
	char				*name;
	char				*path;
	t_stat				*stat;
	struct s_file		*files;
	struct s_file		*prev;
	struct s_file		*next;
}						t_file;

typedef struct			s_arg
{
	char				*name;
	t_bool				f;
	t_stat				*stat;
	struct s_arg		*prev;
	struct s_arg		*next;
}						t_arg;

typedef struct			s_ls
{
	t_opt				opt;
	t_arg				*arg;
	int					nb_dir;
	t_bool				space;
	int					status;
}						t_ls;

void					get_arg(char *name, t_ls *ls);
void					sort_arg(t_ls *ls);
void					sort_file(t_file *dir, t_opt opt);
void					ft_display(t_file *dir, t_ls *ls);
void					display(t_arg *arg, t_opt opt, t_bool *space);
void					l_display(t_file *file, t_max len);
void					total(t_file *dir, t_opt opt);
void					init_len(t_max *len);
void					get_len(t_file *dir, t_max *len, t_opt opt);
void					free_ls(t_ls *ls);
void					free_dir(t_file *dir, t_opt opt);
void					free_files(t_file *file, t_opt opt);
void					ft_ls(char *name, char *path, t_ls *ls);
int						get_opt(char **av, t_ls *ls);
int						arg_size(t_arg *arg);
int						file_size(t_file *file);
void					push_file(t_file *dir, t_dirent *file);
t_stat					*get_stat(char *path, t_dirent *file);
quad_t					sizer(quad_t n);

#endif
