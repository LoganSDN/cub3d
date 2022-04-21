/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emortier <emortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:18:53 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/21 14:23:46 by emortier         ###   ########.fr       */
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
}
