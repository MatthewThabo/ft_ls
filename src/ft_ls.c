/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:25:53 by tmatlena          #+#    #+#             */
/*   Updated: 2018/08/31 12:43:29 by tmatlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		main(int argc, char **argv)
{
	t_ls	*ls;

	if (!(ls = (t_ls *)malloc(sizeof(t_ls))))
		return (ft_printf("Error malloc\n%@", 2));
	*ls = (t_ls){ft_parse(argc, argv, "lraRtu"),
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1};
	if (!ls->parse)
		return (-1);
	if (PARSE->opt & 0x800)
		PARSE->opt &= ~FT_LS_L;
	ft_treat_args(ls);
	ft_free_parse(PARSE);
	free(ls);
	return (1);
}
