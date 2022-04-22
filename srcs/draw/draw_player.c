/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:18:53 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/22 07:48:01 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	draw_player(t_data *d)
{
	int		i;
	int		j;
	t_v2	player;
	t_v2f	compass;

	i = -10;
	while (++i < 10)
	{
		j = -10;
		while (++j < 10)
			put_pxl_to_img(j + d->player.x, i + d->player.y, 0x00FFFF, d);
	}
	player = v2(d->player.x, d->player.y);
	compass = v2f(player.x + (d->dir_player.x * 20), \
		player.y + (d->dir_player.y * 20));
	draw_line_f(d, player, compass, 0xFF0000);
	ft_rayscasting(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.img, 0, 0);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->tex.so_tex.ptr, 0, 0);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->tex.no_tex.ptr, 0, 32);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->tex.ea_tex.ptr, \
	0, 32 * 2);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->tex.we_tex.ptr, \
	0, 32 * 3);
}
