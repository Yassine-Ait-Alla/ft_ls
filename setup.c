/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 11:33:26 by yaitalla          #+#    #+#             */
/*   Updated: 2015/10/30 17:12:50 by yaitalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void		get_perm(mode_t mode, char **ret)
{
	(*ret)[1] = (mode & S_IRUSR) ? 'r' : '-';
	(*ret)[2] = (mode & S_IWUSR) ? 'w' : '-';
	if (mode & S_IXUSR)
		(*ret)[3] = (mode & S_ISUID) ? 's' : 'x';
	else
		(*ret)[3] = (mode & S_ISUID) ? 'S' : '-';
	(*ret)[4] = (mode & S_IRGRP) ? 'r' : '-';
	(*ret)[5] = (mode & S_IWGRP) ? 'w' : '-';
	if (mode & S_IXGRP)
		(*ret)[6] = (mode & S_ISGID) ? 's' : 'x';
	else
		(*ret)[6] = (mode & S_ISGID) ? 'S' : '-';
	(*ret)[7] = (mode & S_IROTH) ? 'r' : '-';
	(*ret)[8] = (mode & S_IWOTH) ? 'w' : '-';
	if (mode & S_IXOTH)
		(*ret)[9] = (mode & S_ISVTX) ? 't' : 'x';
	else
		(*ret)[9] = (mode & S_ISVTX) ? 'T' : '-';
}

static void		get_mode(mode_t mode, char **ret, t_stat *s)
{
	if (S_ISFIFO(mode))
		(*ret)[0] = 'p';
	if (S_ISCHR(mode))
		(*ret)[0] = 'c';
	if (S_ISDIR(mode))
		(*ret)[0] = 'd';
	if (S_ISBLK(mode))
		(*ret)[0] = 'b';
	if (S_ISREG(mode))
		(*ret)[0] = '-';
	if (S_ISLNK(mode))
		(*ret)[0] = 'l';
	if (S_ISSOCK(mode))
		(*ret)[0] = 's';
	get_perm(mode, ret);
	s->mode = *ret;
}

static void		get_usr_grp(uid_t uid, gid_t gid, t_stat *s)
{
	if (getpwuid(uid))
		s->usr = ft_strdup(getpwuid(uid)->pw_name);
	else
		s->usr = ft_itoa(uid);
	if (getgrgid(gid))
		s->grp = ft_strdup(getgrgid(gid)->gr_name);
	else
		s->grp = ft_itoa(gid);
}

static char		*get_time(time_t mtime)
{
	char		*date;
	char		*year;
	char		*hour;

	date = ctime(&mtime);
	hour = ft_strdup(&(date[11]));
	hour[5] = '\0';
	year = ft_strdup(&(date[19]));
	year[5] = '\0';
	date[11] = '\0';
	if (mtime > time(0) || time(0) - mtime > 15778463)
		date = ft_strjoin(&(date[4]), year);
	else
		date = ft_strjoin(&(date[4]), hour);
	free(hour);
	free(year);
	return (date);
}

t_stat			*get_stat(char *path, t_dirent *file)
{
	struct stat	st;
	t_stat		*s;
	char		*buf;
	char		*mode;

	s = (t_stat*)malloc(sizeof(t_stat));
	buf = ft_memalloc(256);
	mode = ft_memalloc(11);
	if (file && file->d_type == DT_LNK)
		lstat(path, &st);
	else
		stat(path, &st);
	get_mode(st.st_mode, &mode, s);
	s->lnk = st.st_nlink;
	get_usr_grp(st.st_uid, st.st_gid, s);
	s->major = major(st.st_rdev);
	s->minor = minor(st.st_rdev);
	s->size = st.st_size;
	s->mtime = get_time(st.st_mtime);
	s->time = st.st_mtime;
	if (file && file->d_type == DT_LNK)
		readlink(path, buf, 256);
	s->lnk_name = buf;
	s->blocks = st.st_blocks;
	return (s);
}
