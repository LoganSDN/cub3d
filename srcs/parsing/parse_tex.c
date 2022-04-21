/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 08:29:05 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/21 07:47:29 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	get_north(t_data *d, int i, int *j, int *order)
{
	if (!ft_strncmp(d->map[i] + (*j), "NO", 2))
	{
		(*j) += 2;
		while (ft_isspace(d->map[i][*j]))
			(*j) += 1;
		d->tex.no_tex = ft_strdup(d->map[i] + (*j));
		if (!d->tex.no_tex)
			ft_putstr_fd("Error\n", 2);
		(*order)++;
	}
}

void	get_south(t_data *d, int i, int *j, int *order)
{
	if (!ft_strncmp(d->map[i] + (*j), "SO", 2))
	{
		(*j) += 2;
		while (ft_isspace(d->map[i][*j]))
			(*j) += 1;
		d->tex.so_tex = ft_strdup(d->map[i] + (*j));
		if (!d->tex.so_tex)
			ft_putstr_fd("Error\n", 2);
		(*order)++;
	}
}

void	get_west(t_data *d, int i, int *j, int *order)
{
	if (!ft_strncmp(d->map[i] + (*j), "WE", 2))
	{
		(*j) += 2;
		while (ft_isspace(d->map[i][*j]))
			(*j) += 1;
		d->tex.we_tex = ft_strdup(d->map[i] + (*j));
		if (!d->tex.we_tex)
			ft_putstr_fd("Error\n", 2);
		(*order)++;
	}
}

void	get_east(t_data *d, int i, int *j, int *order)
{
	if (!ft_strncmp(d->map[i] + (*j), "EA", 2))
	{
		(*j) += 2;
		while (ft_isspace(d->map[i][*j]))
			(*j) += 1;
		d->tex.ea_tex = ft_strdup(d->map[i] + (*j));
		if (!d->tex.ea_tex)
			ft_putstr_fd("Error\n", 2);
		(*order)++;
	}
}

void	get_tex(t_data	*d, int i, int *j, int *order)
{
	get_north(d, i, j, order);
	get_south(d, i, j, order);
	get_west(d, i, j, order);
	get_east(d, i, j, order);
}
