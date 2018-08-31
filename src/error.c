/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 11:35:14 by tmatlena          #+#    #+#             */
/*   Updated: 2018/08/31 11:35:19 by tmatlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*ft_joinpath(char *name)
{
	if (ft_strlen(name) == 1 && *name == '/')
		return (ft_strdup(name));
	else if (!ft_strcmp("./", name) || !ft_strcmp("../", name))
		return (ft_strdup(name));
	return (ft_strjoin(name, "/"));
}

int		ft_is_error_to_treat(t_ls *ls, char *name)
{
	t_list	*tmp;

	tmp = PARSE->args;
	while (tmp)
	{
		if (!ft_strcmp(tmp->content, name))
			return (2);
		tmp = tmp->next;
	}
	if (*name != '.')
		return (1);
	else if ((ft_strcmp(".", name) && ft_strcmp("..", name)) &&
		PARSE->opt & FT_LS_MA)
		return (1);
	else if (PARSE->opt & FT_LS_A)
		return (1);
	return (0);
}

int		ft_treaterror(char *name)
{
	int		i;

	ft_printf("ft_ls: %@", 2);
	i = ft_strlen(name);
	while (i != 0 && name[i] != '/')
		i--;
	if (name[i] == '/')
		i++;
	perror(name + i);
	return (-1);
}
