/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emortier <emortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:24:35 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/22 16:16:08 by emortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	verLine(t_data *d, int x, int y, int y2, int color)
{
	while (y++ <= y2)
		put_pxl_to_img(WIDTH - x, y, color, d);
}

void	ft_rayscasting(t_data *d)
{
	double	angle;
	double	step;
	int		i;
	int		color;
	double	theta;
	t_ray	ray;

	i = 0;
	step = (M_PI / 3) / d->nb_rays;
	while (i <= d->nb_rays)
	{
		angle = fmod((d->player_angle - M_PI / 6) + step * i, 2 * M_PI);
		ray = ft_ray(d, angle);
		theta = fmod(fabs(d->player_angle - angle), 2 * M_PI);
		if (ray.side == 1)
		{
			ray.wall = ray.wall * cos(theta);
			color = 0x0000FF;
		}
		else
		{
			ray.wall = ray.wall * cos(theta);
			color = 0xFF00000;
		}
		int line_h = HEIGHT / ray.wall;
		int drawStart = -line_h / 2 + HEIGHT / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = line_h / 2 + HEIGHT / 2;
		if (drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;
		verLine(d, i , 0, drawStart, d->tex.ceil_col.value);
		verLine(d, i, drawStart, drawEnd, color);
		verLine(d, i , drawEnd, HEIGHT, d->tex.floor_col.value);
		angle += step;
		// if (i == WIDTH / 2)
		// 	draw_angle(d, ray.wall * d->ratio.y, ray.ray_dir, 0xff0000);
		// else
		// 	draw_angle(d, ray.wall * d->ratio.y, ray.ray_dir, 0x00ff00);
		i++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.img, 0, 0);
}

//  if(side == 0) 
//  	perpWallDist = (sideDistX - deltaDistX);
// else          
// 	perpWallDist = (sideDistY - deltaDistY);

t_ray	ft_ray(t_data *d, double angle)
{
	int		wall;
	t_ray	ray;

	wall = 0;
	ray = ft_init_rays(d, angle);
	while (!wall)
	{
		wall = ft_isawall(d, ray);
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
