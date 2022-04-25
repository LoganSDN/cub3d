/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:24:35 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/25 15:18:17 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	draw_wall(t_data *d, int col, int start, int end, t_ray ray)
{
	int		i;
	int		z;
	int		color;

	i = -1;
	while (++i <= start)
	{
		put_pxl_to_img(WIDTH - col, i, d->tex.ceil_col.value, d);
		put_pxl_to_img(WIDTH - col, end + i, d->tex.floor_col.value, d);
	}
	i = 0;
	z = 0;
	while (i  <= end - start)
	{
		if (ray.side == 1)
		{
			z = i * 32 / (HEIGHT / ray.wall);
			if (ray.ray_angle > M_PI)
				color = *(int *)(d->tex.tex[0].img.img_ptr + (((d->tex.tex[0].img.sl * z) + (int) ((int)(ray.pos.x * 32) * d->tex.tex[0].img.bpp))));
			else
				color = *(int *)(d->tex.tex[2].img.img_ptr + (((d->tex.tex[2].img.sl * z) + (int) ((int)(ray.pos.x * 32) * d->tex.tex[2].img.bpp))));
			put_pxl_to_img(WIDTH - col, i + start, color, d);
		}
		else
		{
			z = i * 32 / (HEIGHT / ray.wall);
			if (ray.ray_angle > M_PI_2 && ray.ray_angle < 3 * M_PI_2)
				color = *(int *)(d->tex.tex[1].img.img_ptr + (((d->tex.tex[1].img.sl * z) + (int) ((int)(ray.pos.y  * 32) * d->tex.tex[1].img.bpp))));
			else
				color = *(int *)(d->tex.tex[3].img.img_ptr + (((d->tex.tex[3].img.sl * z) + (int) ((int)(ray.pos.y * 32) * d->tex.tex[3].img.bpp))));
			put_pxl_to_img(WIDTH - col, i + start, color, d);
		}
		i++;
	}
}

		// if (ray.side)
		// 	put_pxl_to_img(WIDTH - col, i++, 0x050778, d);
		// else
		// 	put_pxl_to_img(WIDTH - col, i++, 0x050778 << 2, d);
void	ft_draw_wall(t_data *d, t_ray ray, int w)
{
	int		wall_height;
	int		wall_start;
	int		wall_end;

	wall_height = HEIGHT / ray.wall;
	wall_start = (HEIGHT - wall_height) / 2;
	if (wall_start < 0)
		wall_start = 0;
	wall_end = (HEIGHT + wall_height) / 2;
	if (wall_end >= HEIGHT)
		wall_end = HEIGHT - 1;
	draw_wall(d, w, wall_start, wall_end, ray);
}

void	ft_fixeye(t_ray *ray, double angle)
{
	double	theta;

	theta = fmod(fabs(angle), 2 * M_PI);
	if ((*ray).side == 1)
		(*ray).wall = (*ray).wall * cos(theta);
	else
		(*ray).wall = (*ray).wall * cos(theta);
}

void	ft_rayscasting(t_data *d)
{
	double	angle;
	double	step;
	int		i;
	t_ray	ray;

	i = 0;
	step = (M_PI / 2) / d->nb_rays;
	while (i < d->nb_rays)
	{
		angle = fmod((d->player_angle - M_PI / 4) + step * i, 2 * M_PI);
		ray = ft_ray(d, angle);
		ft_fixeye(&ray, d->player_angle - angle);
		ft_draw_wall(d, ray, i);
		angle += step;
		i++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.img, 0, 0);
}

t_ray	ft_ray(t_data *d, double angle)
{
	int		wall;
	t_ray	ray;

	wall = 0;
	ray = ft_init_rays(d, angle);
	while (!wall)
	{
		wall = ft_isawall(d, &ray);
		if (ray.dist.x > ray.dist.y)
		{
			ray.wall = fabs(ray.dist.y);
			ray.nb.y += ray.dir.y;
			ray.dist.y = fabs(ray.dir.y * ray.nb.y / ray.theta_ang.y);
			ray.side = 1;
		}
		else
		{
			ray.wall = fabs(ray.dist.x);
			ray.nb.x += ray.dir.x;
			ray.dist.x = fabs(ray.dir.x * ray.nb.x / ray.theta_ang.x);
			ray.side = 0;
		}
	}
	return (ray);
}
