/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emortier <emortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:13:08 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/22 17:45:29 by emortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	init(t_data *d, int fd)
{
	d->map = join_and_split(d, fd);
	d->mlx_ptr = mlx_init();
	mlx_do_key_autorepeaton(d->mlx_ptr);
	get_desc(d);
	d->dir_player = v2f(cos(d->player_angle), sin(d->player_angle));
	d->nb_rays = WIDTH;
	d->img.img = mlx_new_image(d->mlx_ptr, WIDTH + 1, HEIGHT + 1);
	d->img.img_ptr = mlx_get_data_addr(d->img.img, &d->img.bpp, \
		&d->img.sl, &d->img.endian);
	d->img.bpp /= 8;
	d->win_ptr = mlx_new_window(d->mlx_ptr, \
		WIDTH, HEIGHT, "cub3d");
}
