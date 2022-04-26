/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 08:29:05 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/26 13:21:33 by lsidan           ###   ########lyon.fr   */
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
		d->tex.tex[0].path = ft_strtrim(ft_strdup(d->map[i] + (*j)), " ");
		if (!d->tex.tex[0].path)
			ft_error("Unable to copy the path of 'NO_tex'\n", d);
		d->tex.tex[0].img.img = mlx_xpm_file_to_image(d->mlx_ptr, \
		d->tex.tex[0].path, &d->tex.tex[0].width, &d->tex.tex[0].height);
		if (!d->tex.tex[0].img.img)
			ft_error("Error while opening 'NO_tex'. Check your path\n", d);
		d->tex.tex[0].img.img_ptr = mlx_get_data_addr(d->tex.tex[0].img.img, \
		&d->tex.tex[0].img.bpp, &d->tex.tex[0].img.sl, \
		&d->tex.tex[0].img.endian);
		if (!d->tex.tex[0].img.img_ptr)
			ft_error("Error while getting 'NO_tex' adress.\n", d);
		d->tex.tex[0].img.bpp /= 8;
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
		d->tex.tex[2].path = ft_strtrim(ft_strdup(d->map[i] + (*j)), " ");
		if (!d->tex.tex[2].path)
			ft_error("Unable to copy the path of 'SO_tex'\n", d);
		d->tex.tex[2].img.img = mlx_xpm_file_to_image(d->mlx_ptr, \
		d->tex.tex[2].path, &d->tex.tex[2].width, &d->tex.tex[2].height);
		if (!d->tex.tex[2].img.img)
			ft_error("Error while opening 'SO_tex'. Check your path\n", d);
		d->tex.tex[2].img.img_ptr = mlx_get_data_addr(d->tex.tex[2].img.img, \
		&d->tex.tex[2].img.bpp, &d->tex.tex[2].img.sl, \
		&d->tex.tex[2].img.endian);
		if (!d->tex.tex[2].img.img_ptr)
			ft_error("Error while getting 'SO_tex' adress.\n", d);
		d->tex.tex[2].img.bpp /= 8;
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
		d->tex.tex[3].path = ft_strtrim(ft_strdup(d->map[i] + (*j)), " ");
		if (!d->tex.tex[3].path)
			ft_error("Unable to copy the path of 'WE_tex'\n", d);
		d->tex.tex[3].img.img = mlx_xpm_file_to_image(d->mlx_ptr, \
		d->tex.tex[3].path, &d->tex.tex[3].width, &d->tex.tex[3].height);
		if (!d->tex.tex[3].img.img)
			ft_error("Error while opening 'WE_tex'. Check your path\n", d);
		d->tex.tex[3].img.img_ptr = mlx_get_data_addr(d->tex.tex[3].img.img, \
		&d->tex.tex[3].img.bpp, &d->tex.tex[3].img.sl, \
		&d->tex.tex[3].img.endian);
		if (!d->tex.tex[3].img.img_ptr)
			ft_error("Error while getting 'WE_tex' adress.\n", d);
		d->tex.tex[3].img.bpp /= 8;
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
		d->tex.tex[1].path = ft_strtrim(ft_strdup(d->map[i] + (*j)), " ");
		if (!d->tex.tex[1].path)
			ft_error("Unable to copy the path of 'EA_tex'\n", d);
		d->tex.tex[1].img.img = mlx_xpm_file_to_image(d->mlx_ptr, \
		d->tex.tex[1].path, &d->tex.tex[1].width, &d->tex.tex[1].height);
		if (!d->tex.tex[1].img.img)
			ft_error("Error while opening 'EA_tex'. Check your path\n", d);
		d->tex.tex[1].img.img_ptr = mlx_get_data_addr(d->tex.tex[1].img.img, \
		&d->tex.tex[1].img.bpp, &d->tex.tex[1].img.sl, \
		&d->tex.tex[1].img.endian);
		if (!d->tex.tex[1].img.img_ptr)
			ft_error("Error while getting 'EA_tex' adress.\n", d);
		d->tex.tex[1].img.bpp /= 8;
		(*order)++;
	}
}

void	get_tex(t_data	*d, int i, int *j, int *order)
{
	int	tmp;

	tmp = (*order);
	if (!d->tex.tex[0].path)
		get_north(d, i, j, order);
	if (!d->tex.tex[2].path)
		get_south(d, i, j, order);
	if (!d->tex.tex[3].path)
		get_west(d, i, j, order);
	if (!d->tex.tex[1].path)
		get_east(d, i, j, order);
	get_color(d, i, j, order);
	if ((*order) == tmp)
		ft_error("Wrong declaration of texture\n", d);
}
