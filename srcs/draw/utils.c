/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:37:12 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/22 07:46:20 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	put_pxl_to_img(int x, int y, int color, t_data *d)
{
	*(int *)(d->img.img_ptr + (((d->img.sl * y) + (x * d->img.bpp)))) = color;
}

void	draw_square(t_data *d, int color, t_v2f map)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->ratio.y)
	{
		j = 0;
		while (j < d->ratio.x)
		{
			put_pxl_to_img(j + map.x, i + map.y, color, d);
			j++;
		}
		i++;
	}
}

void	draw_line_f(t_data *d, t_v2 src, t_v2f dst, int c)
{
	t_v2d	delta;
	t_v2d	pixel;
	int		pixels;

	delta = v2d(dst.x - src.x, dst.y - src.y);
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= pixels;
	delta.y /= pixels;
	pixel = v2d(src.x, src.y);
	while (pixels)
	{
		put_pxl_to_img(pixel.x, pixel.y, c, d);
		pixel.x += delta.x;
		pixel.y -= delta.y;
		--pixels;
	}
}

void	draw_angle(t_data *d, int len, t_v2f dir, int color)
{
	int	i;

	i = 0;
	while (++i < len)
		put_pxl_to_img(d->player.x + dir.x * i, \
		d->player.y - dir.y * i, color, d);
}

void	draw_line(t_data *d, t_v2 src, t_v2 dst, int c)
{
	t_v2d	delta;
	t_v2d	pixel;
	int		pixels;

	delta = v2d(dst.x - src.x, dst.y - src.y);
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= pixels;
	delta.y /= pixels;
	pixel = v2d(src.x, src.y);
	while (pixels)
	{
		put_pxl_to_img(pixel.x, pixel.y, c, d);
		pixel.x += delta.x;
		pixel.y -= delta.y;
		--pixels;
	}
}
