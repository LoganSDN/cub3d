/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:02:17 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/26 11:04:56 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	get_color(t_data *d, int i, int *j, int *order)
{
	d->tex.count = 0;
	get_floor(d, i, j, order);
	d->tex.count = 0;
	get_ceil(d, i, j, order);
}

void	get_floor_2(t_data *d, int i, int *j, int *order)
{
	(*j) += 1;
	skip_space(d, i, j, 1);
	if (ft_atoi(d->map[i] + (*j)) <= 255 && ft_atoi(d->map[i] + (*j)) >= 0)
		d->tex.floor_col.rgb.b = ft_atoi(d->map[i] + (*j));
	else
		ft_error("Check your range of 'floor color'\n", d);
	d->tex.count++;
	(*j) += count_digits(d->tex.floor_col.rgb.b);
	skip_space(d, i, j, 0);
	if (ft_atoi(d->map[i] + (*j)) <= 255 && ft_atoi(d->map[i] + (*j)) >= 0)
		d->tex.floor_col.rgb.g = ft_atoi(d->map[i] + (*j));
	else
		ft_error("Check your range of 'floor color'\n", d);
	d->tex.count++;
	(*j) += count_digits(d->tex.floor_col.rgb.g);
	skip_space(d, i, j, 0);
	if (ft_atoi(d->map[i] + (*j)) <= 255 && ft_atoi(d->map[i] + (*j)) >= 0)
		d->tex.floor_col.rgb.r = ft_atoi(d->map[i] + (*j));
	else
		ft_error("Check your range of 'floor color'\n", d);
	d->tex.count++;
	(*j) += count_digits(d->tex.floor_col.rgb.r);
	check_color_count(d, i, j);
	d->tex.floor_col.rgb.a = 0;
	(*order)++;
}

void	get_floor(t_data *d, int i, int *j, int *order)
{
	if (!ft_strncmp(d->map[i] + (*j), "F", 1))
		get_floor_2(d, i, j, order);
}

void	get_ceil2(t_data *d, int i, int *j, int *order)
{
	(*j) += 1;
	skip_space(d, i, j, 1);
	if (ft_atoi(d->map[i] + (*j)) <= 255 && ft_atoi(d->map[i] + (*j)) >= 0)
		d->tex.ceil_col.rgb.b = ft_atoi(d->map[i] + (*j));
	else
		ft_error("Check your range of 'Ceil color'\n", d);
	d->tex.count++;
	(*j) += count_digits(d->tex.ceil_col.rgb.b);
	skip_space(d, i, j, 0);
	if (ft_atoi(d->map[i] + (*j)) <= 255 && ft_atoi(d->map[i] + (*j)) >= 0)
		d->tex.ceil_col.rgb.g = ft_atoi(d->map[i] + (*j));
	else
		ft_error("Check your range of 'Ceil color'\n", d);
	d->tex.count++;
	(*j) += count_digits(d->tex.ceil_col.rgb.g);
	skip_space(d, i, j, 0);
	if (ft_atoi(d->map[i] + (*j)) <= 255 && ft_atoi(d->map[i] + (*j)) >= 0)
		d->tex.ceil_col.rgb.r = ft_atoi(d->map[i] + (*j));
	else
		ft_error("Check your range of 'Ceil color'\n", d);
	d->tex.count++;
	(*j) += count_digits(d->tex.ceil_col.rgb.r);
	check_color_count(d, i, j);
	d->tex.ceil_col.rgb.a = 0;
	(*order)++;
}

void	get_ceil(t_data *d, int i, int *j, int *order)
{
	if (!ft_strncmp(d->map[i] + (*j), "C", 1))
	{
		get_ceil2(d, i, j, order);
	}
}
