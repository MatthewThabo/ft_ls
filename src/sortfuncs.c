/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:43:40 by tmatlena          #+#    #+#             */
/*   Updated: 2018/08/31 12:09:16 by tmatlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_sort(t_ls *ls, t_ent *ent1, t_ent *ent2)
{
	long		results;

	if (PARSE->opt & FT_LS_F)
		return (0);
	if (PARSE->opt & FT_LS_T)
	{
		results = PARSE->opt & FT_LS_R ? ent1->sec - ent2->sec :
			ent2->sec - ent1->sec;
		if (results == 0)
			results = PARSE->opt & FT_LS_R ? ent1->nsec - ent2->nsec :
			ent2->nsec - ent1->nsec;
		if (results == 0)
		{
			return (PARSE->opt & FT_LS_R ? ft_strcmp(ent2->name, ent1->name) :
				ft_strcmp(ent1->name, ent2->name));
		}
		return (results);
	}
	else
	{
		return (PARSE->opt & FT_LS_R ? ft_strcmp(ent2->name, ent1->name) :
			ft_strcmp(ent1->name, ent2->name));
	}
}
