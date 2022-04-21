/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:13:08 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/21 11:36:06 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	init(t_data *d, int fd)
{
	int	i;

	i = 0;
	d->map = join_and_split(d, fd);
	// d->mlx_ptr = mlx_init();
	// mlx_do_key_autorepeaton(d->mlx_ptr);
	get_desc(d);
	d->dir_player = v2f(cos(d->player_angle), sin(d->player_angle));
	d->img.height = d->map_height * d->ratio.y;
	d->img.width = d->map_len * d->ratio.x;
	// d->img.img = mlx_new_image(d->mlx_ptr, d->img.height, d->img.width);
	// d->img.img_ptr = mlx_get_data_addr(d->img.img, &d->img.bpp, \
	// 	&d->img.sl, &d->img.endian);
	// d->img.bpp /= 8;
	// d->win_ptr = mlx_new_window(d->mlx_ptr, \
	// 	d->img.width, d->img.height, "cub3d");
}
