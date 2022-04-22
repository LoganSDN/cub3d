/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 07:55:31 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/22 09:00:18 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	get_desc(t_data *d)
{
	int	i;
	int	j;
	int	order;

	order = 0;
	i = -1;
	while (d->map[++i])
	{
		j = 0;
		while (ft_isspace(d->map[i][j]))
			j++;
		if (j == ft_strlen(d->map[i]))
			continue ;
		if (order < 6)
		{
			get_tex(d, i, &j, &order);
			get_color(d, i, &j, &order);
			continue ;
		}
		if (order == 6)
		{
			check_map(d, d->map + i);
			break ;
		}
	}
	if (order < 6)
		ft_error("map's desc is not in the right order. \
		(Map must be at the EOF)\n");
}
