/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:26:45 by tmatlena          #+#    #+#             */
/*   Updated: 2018/08/31 11:41:54 by tmatlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	ft_getusermode(LS_STAT *info, char *mode)
{
	LS_MODE & S_IRUSR ? ft_strcat(mode, "r") : ft_strcat(mode, "-");
	LS_MODE & S_IWUSR ? ft_strcat(mode, "w") : ft_strcat(mode, "-");
	if (LS_MODE & S_ISUID)
		LS_MODE & S_IXUSR ? ft_strcat(mode, "s") : ft_strcat(mode, "S");
	else
		LS_MODE & S_IXUSR ? ft_strcat(mode, "x") : ft_strcat(mode, "-");
	LS_MODE & S_IRGRP ? ft_strcat(mode, "r") : ft_strcat(mode, "-");
	LS_MODE & S_IWGRP ? ft_strcat(mode, "w") : ft_strcat(mode, "-");
	if (LS_MODE & S_ISGID)
		LS_MODE & S_IXGRP ? ft_strcat(mode, "s") : ft_strcat(mode, "S");
	else
		LS_MODE & S_IXGRP ? ft_strcat(mode, "x") : ft_strcat(mode, "-");
	LS_MODE & S_IROTH ? ft_strcat(mode, "r") : ft_strcat(mode, "-");
	LS_MODE & S_IWOTH ? ft_strcat(mode, "w") : ft_strcat(mode, "-");
	if (LS_MODE & S_ISVTX)
		LS_MODE & S_IXOTH ? ft_strcat(mode, "t") : ft_strcat(mode, "T");
	else
		LS_MODE & S_IXOTH ? ft_strcat(mode, "x") : ft_strcat(mode, "-");
}

char		*ft_getlnk(LS_STAT *info, char *name, char *path)
{
	char	*fullpath;
	char	*buf;
	char	*res;
	size_t	bufsize;

	if (S_ISLNK(LS_MODE))
	{
		fullpath = ft_strjoin(path, name);
		buf = ft_strnew(256);
		bufsize = 255;
		if (readlink(fullpath, buf, bufsize) == -1 && ft_printf("ft_ls: %@", 2))
			perror(fullpath);
		res = ft_strjoin(" -> ", buf);
		FT_MEMDEL(fullpath);
		FT_MEMDEL(buf);
		return (res);
	}
	else
		return (NULL);
}

char		*ft_getmode(LS_STAT *info)
{
	char	*mode;

	mode = ft_strnew(11);
	if (S_IFIFO & LS_MODE)
		ft_strcat(mode, "p");
	if (S_ISBLK(LS_MODE))
		ft_strcat(mode, "b");
	else if (S_ISCHR(LS_MODE))
		ft_strcat(mode, "c");
	else if (S_ISREG(LS_MODE))
		ft_strcat(mode, "-");
	else if (S_ISLNK(LS_MODE))
		ft_strcat(mode, "l");
	else if (S_ISSOCK(LS_MODE))
		ft_strcat(mode, "s");
	else if (S_ISWHT(LS_MODE))
		ft_strcat(mode, "w");
	else if (S_ISDIR(LS_MODE))
		ft_strcat(mode, "d");
	ft_getusermode(info, mode);
	return (mode);
}
