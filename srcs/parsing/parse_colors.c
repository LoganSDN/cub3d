/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:02:17 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/26 09:38:21 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	get_color(t_data *d, int i, int *j, int *order)
{
	get_floor(d, i, j, order);
	get_ceil(d, i, j, order);
}

void	get_floor(t_data *d, int i, int *j, int *order)
{
	if (!ft_strncmp(d->map[i] + (*j), "F", 1))
	{
		(*j) += 1;
		while (ft_isspace(d->map[i][*j]))
			(*j)++;
		if (ft_atoi(d->map[i] + (*j)) <= 255 && ft_atoi(d->map[i] + (*j)) >= 0)
			d->tex.floor_col.rgb.b = ft_atoi(d->map[i] + (*j));
		(*j) += count_digits(d->tex.floor_col.rgb.b);
		while (ft_isspace(d->map[i][*j]) || d->map[i][*j] == ',')
			(*j)++;
		if (ft_atoi(d->map[i] + (*j)) <= 255 && ft_atoi(d->map[i] + (*j)) >= 0)
			d->tex.floor_col.rgb.g = ft_atoi(d->map[i] + (*j));
		(*j) += count_digits(d->tex.floor_col.rgb.g);
		while (ft_isspace(d->map[i][*j]) || d->map[i][*j] == ',')
			(*j)++;
		if (ft_atoi(d->map[i] + (*j)) <= 255 && ft_atoi(d->map[i] + (*j)) >= 0)
			d->tex.floor_col.rgb.r = ft_atoi(d->map[i] + (*j));
		(*j) += count_digits(d->tex.floor_col.rgb.r);
		d->tex.floor_col.rgb.a = 0;
		(*order)++;
	}
}

void	get_ceil(t_data *d, int i, int *j, int *order)
{
	if (!ft_strncmp(d->map[i] + (*j), "C", 1))
	{
		(*j) += 1;
		while (ft_isspace(d->map[i][*j]))
			(*j)++;
		if (ft_atoi(d->map[i] + (*j)) <= 255 && ft_atoi(d->map[i] + (*j)) >= 0)
			d->tex.ceil_col.rgb.b = ft_atoi(d->map[i] + (*j));
		(*j) += count_digits(d->tex.ceil_col.rgb.b);
		while (ft_isspace(d->map[i][*j]) || d->map[i][*j] == ',')
			(*j)++;
		if (ft_atoi(d->map[i] + (*j)) <= 255 && ft_atoi(d->map[i] + (*j)) >= 0)
			d->tex.ceil_col.rgb.g = ft_atoi(d->map[i] + (*j));
		(*j) += count_digits(d->tex.ceil_col.rgb.g);
		while (ft_isspace(d->map[i][*j]) || d->map[i][*j] == ',')
			(*j)++;
		if (ft_atoi(d->map[i] + (*j)) <= 255 && ft_atoi(d->map[i] + (*j)) >= 0)
			d->tex.ceil_col.rgb.r = ft_atoi(d->map[i] + (*j));
		(*j) += count_digits(d->tex.ceil_col.rgb.r);
		d->tex.ceil_col.rgb.a = 0;
		(*order)++;
	}
}
