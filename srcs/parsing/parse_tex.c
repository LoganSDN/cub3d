/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 08:29:05 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/22 08:01:49 by lsidan           ###   ########lyon.fr   */
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
		d->tex.no_tex.path = ft_strdup(d->map[i] + (*j));
		if (!d->tex.no_tex.path)
			ft_error("Unable to copy the path of 'NO_tex'\n");
		d->tex.no_tex.ptr = mlx_xpm_file_to_image(d->mlx_ptr, \
		d->tex.no_tex.path, &d->tex.no_tex.width, &d->tex.no_tex.height);
		if (!d->tex.no_tex.ptr)
			ft_error("Error while opening 'NO_tex'. Check your path\n");
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
		d->tex.so_tex.path = ft_strdup(d->map[i] + (*j));
		if (!d->tex.so_tex.path)
			ft_error("Unable to copy the path of 'SO_tex'\n");
		d->tex.so_tex.ptr = mlx_xpm_file_to_image(d->mlx_ptr, \
		d->tex.so_tex.path, &d->tex.so_tex.width, &d->tex.so_tex.height);
		if (!d->tex.so_tex.ptr)
			ft_error("Error while opening 'SO_tex'. Check your path\n");
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
		d->tex.we_tex.path = ft_strdup(d->map[i] + (*j));
		if (!d->tex.we_tex.path)
			ft_error("Unable to copy the path of 'WE_tex'\n");
		d->tex.we_tex.ptr = mlx_xpm_file_to_image(d->mlx_ptr, \
		d->tex.we_tex.path, &d->tex.we_tex.width, &d->tex.we_tex.height);
		if (!d->tex.we_tex.ptr)
			ft_error("Error while opening 'WE_tex'. Check your path\n");
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
		d->tex.ea_tex.path = ft_strdup(d->map[i] + (*j));
		if (!d->tex.ea_tex.path)
			ft_error("Unable to copy the path of 'EA_tex'\n");
		d->tex.ea_tex.ptr = mlx_xpm_file_to_image(d->mlx_ptr, \
		d->tex.ea_tex.path, &d->tex.ea_tex.width, &d->tex.ea_tex.height);
		if (!d->tex.ea_tex.ptr)
			ft_error("Error while opening 'EA_tex'. Check your path\n");
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
