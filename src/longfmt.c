/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longfmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:27:41 by tmatlena          #+#    #+#             */
/*   Updated: 2018/08/31 11:50:05 by tmatlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*ft_getturfudate(time_t *sec)
{
	char	*res;
	char	*str1;
	char	*str2;

	str1 = ft_strsub(ctime(sec), 4, 7);
	str2 = ft_strsub(ctime(sec), 19, 5);
	res = ft_strjoin(str1, str2);
	FT_MEMDEL(str1);
	FT_MEMDEL(str2);
	return (res);
}

char	*ft_getdate(t_ls *ls, LS_STAT *info)
{
	if (PARSE->opt & FT_LS_U)
	{
		if (time(NULL) > ATIME && time(NULL) - MONTHS < ATIME)
			return (ft_strsub(ctime(&ATIME), 4, 12));
		else
			return (ft_getturfudate(&ATIME));
	}
	else if (PARSE->opt & FT_LS_MU)
	{
		if (time(NULL) > CTIME && time(NULL) - MONTHS < CTIME)
			return (ft_strsub(ctime(&CTIME), 4, 12));
		else
			return (ft_getturfudate(&CTIME));
	}
	else
	{
		if (time(NULL) > MTIME && (time(NULL) - MONTHS) < MTIME)
			return (ft_strsub(ctime(&MTIME), 4, 12));
		else
			return (ft_getturfudate(&MTIME));
	}
}

char    *ft_getgroup(t_ls *ls, LS_STAT *info)
{
	struct group    *grp;
	char			*group;

	if ((grp = getgrgid(info->st_gid)) != NULL)
		group = ft_strdup(grp->gr_name);
	else
		group = ft_itoa(info->st_gid);
	if (ls->l_group == 0 || ls->l_group < (long)ft_strlen(group))
		ls->l_group = ft_strlen(group);
	return (group);
}

char	*ft_getuname(t_ls *ls, LS_STAT *info)
{
	struct passwd	*passwd;
	char			*uname;

	if ((passwd = getpwuid(info->st_uid)) != NULL)
		uname = ft_strdup(passwd->pw_name);
	else
		uname = ft_itoa(info->st_uid);
	if (ls->l_user == 0 || ls->l_user < (long)ft_strlen(uname))
		ls->l_user = ft_strlen(uname);
	return (uname);
}

void	ft_getnbytes(t_ls *ls, LS_STAT *info, t_ent *ent)
{
	if ((S_ISCHR(LS_MODE) || S_ISBLK(LS_MODE)) && !(LS_MODE & S_IFDIR))
	{
		ent->major = ft_itoa(major(info->st_rdev));
		ent->minor = ft_itoa(minor(info->st_rdev));
		if (ls->l_major < (long)ft_strlen(ent->major))
			ls->l_major = ft_strlen(ent->major);
		if (ls->l_minor < (long)ft_strlen(ent->minor))
			ls->l_minor = ft_strlen(ent->minor);
	}
	else
	{
		ent->nb_bytes = ft_itoa(info->st_size);
		if (ls->l_major + ls->l_minor + 1 < (long)ft_strlen(ent->nb_bytes) &&
				ls->l_nbytes < (long)ft_strlen(ent->nb_bytes))
			ls->l_nbytes = ft_strlen(ent->nb_bytes);
	}
	if (ft_is_to_print(ls, ent))
		ls->total += info->st_blocks;
}
