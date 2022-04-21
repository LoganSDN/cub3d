/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emortier <emortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:36:21 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/21 14:00:02 by emortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	ft_whereinmap(t_data *d, float x0, float y0)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < WIDTH / d->map_len)
	{
		x = -1;
		while (++x < HEIGHT / d->map_height)
		{
			if (y == 0 || y == WIDTH / d->map_len - 1)
				put_pxl_to_img(x0 * d->ratio.x + x, y0 * \
				d->ratio.y, 0x762786, d);
			else if (x <= 4 || x >= HEIGHT / d->map_height - 4)
				put_pxl_to_img(x0 * d->ratio.x + x, y0 * d->ratio.y + y, \
				0x762786, d);
		}
	}
}

void	draw_map(t_data *d)
{
	int		i;
	int		j;
	t_v2f	map;

	i = 0;
	map = v2f(0, 0);
	while (i < d->map_height)
	{
		j = 0;
		map.x = 0;
		while (j < d->map_len)
		{
			if (d->map[i][j] == '1')
				draw_square(d, 0x0000FF, map);
			else
				draw_square(d, 0xFFFFFF, map);
			j++;
			map.x = j * d->ratio.x;
		}
		i++;
		map.y = i * d->ratio.y;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.img, 0, 0);
}
