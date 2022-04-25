/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:18:53 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/25 08:49:12 by lsidan           ###   ########lyon.fr   */
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
			put_pxl_to_img(j + d->player.x * d->ratio.x, \
			i + d->player.y * d->ratio.y, 0x00FFFF, d);
	}
	player = v2(d->player.x * d->ratio.x, d->player.y * d->ratio.y);
	compass = v2f(player.x + (d->dir_player.x * 20), \
		player.y + (d->dir_player.y * 20));
	draw_line_f(d, player, compass, 0xFF0000);
	ft_rayscasting(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.img_ptr, 0, 0);
}
