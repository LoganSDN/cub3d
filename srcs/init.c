/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:13:08 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/26 11:13:51 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	init(t_data *d, int fd)
{
	d->map = join_and_split(d, fd);
	if (!d->map)
		ft_error("Malloc crash\n", d);
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
		ft_error("Mlx crash\n", d);
	mlx_do_key_autorepeaton(d->mlx_ptr);
	get_desc(d);
	d->dir_player = v2f(cos(d->player_angle), sin(d->player_angle));
	d->nb_rays = WIDTH;
	d->img.img = mlx_new_image(d->mlx_ptr, WIDTH + 1, HEIGHT + 1);
	if (!d->img.img)
		ft_error("Init img crash\n", d);
	d->img.img_ptr = mlx_get_data_addr(d->img.img, &d->img.bpp, \
		&d->img.sl, &d->img.endian);
	if (!d->img.img_ptr)
		ft_error("Init img crash\n", d);
	d->img.bpp /= 8;
	d->win_ptr = mlx_new_window(d->mlx_ptr, \
		WIDTH, HEIGHT, "cub3d");
	if (!d->win_ptr)
		ft_error("Mlx crash\n", d);
}
