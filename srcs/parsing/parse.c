/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 07:55:31 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/25 18:29:47 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	order_sorter(t_data *d, int *order)
{
	int	i;
	int	j;

	i = -1;
	while (d->map[++i])
	{
		j = 0;
		while (ft_isspace(d->map[i][j]))
			j++;
		if (j == ft_strlen(d->map[i]))
			continue ;
		if ((*order) < 6)
		{
			get_tex(d, i, &j, order);
			get_color(d, i, &j, order);
			continue ;
		}
		if ((*order) == 6)
		{
			check_map(d, d->map + i, order);
			break ;
		}
	}	
}

void	get_desc(t_data *d)
{
	int	order;

	order = 0;
	order_sorter(d, &order);
	if (check_w_h(d))
		ft_error("Textures are not in the same size");
	if (order != 7)
		ft_error("map's desc is not in the right order. \
		(Map must be at the EOF)\n");
}
