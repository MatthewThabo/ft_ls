/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:51:40 by tmatlena          #+#    #+#             */
/*   Updated: 2018/08/31 11:40:02 by tmatlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_ent	*ft_dirdup(t_ent *ent)
{
	t_ent	*dir;

	dir = (t_ent *)malloc(sizeof(t_ent));
	dir->name = ft_strdup(ent->name);
	dir->date = NULL;
	dir->grname = NULL;
	dir->mode = NULL;
	dir->lnk = NULL;
	dir->nb_link = NULL;
	dir->nb_bytes = NULL;
	dir->major = NULL;
	dir->minor = NULL;
	dir->sec = ent->sec;
	dir->nsec = ent->nsec;
	return (dir);
}

void	ft_free_ent(t_ent **ent)
{
	if (ent)
	{
		ft_memdel((void**)&((*ent)->name));
		ft_memdel((void**)&((*ent)->date));
		ft_memdel((void**)&((*ent)->uname));
		ft_memdel((void**)&((*ent)->grname));
		ft_memdel((void**)&((*ent)->mode));
		ft_memdel((void**)&((*ent)->nb_link));
		ft_memdel((void**)&((*ent)->lnk));
		ft_memdel((void**)&((*ent)->nb_bytes));
		ft_memdel((void**)&((*ent)->major));
		ft_memdel((void**)&((*ent)->minor));
		ft_memdel((void**)ent);
	}
}

t_dir	*ft_free_dir(t_dir *dir)
{
	t_dir	*next;

	next = dir->next;
	FT_MEMDEL(dir->path);
	ft_free_ent(&(dir->dir));
	FT_MEMDEL(dir);
	return (next);
}
