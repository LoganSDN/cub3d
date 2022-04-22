/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:24:35 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/22 09:55:37 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	ft_rayscasting(t_data *d)
{
	double	angle;
	double	step;
	int		i;
	t_ray	ray;

	i = 0;
	step = M_PI_2 / d->nb_rays;
	while (i < d->nb_rays)
	{
		angle = fmod((d->player_angle - M_PI_4) + step * i, 2 * M_PI);
		ray = ft_ray(d, angle);
		if (i == WIDTH / 2)
			draw_angle(d, ray.wall * d->ratio.x, ray.ray_dir, 0xFF0000);
		else
			draw_angle(d, ray.wall * d->ratio.x, ray.ray_dir, 0x00FF00);
		angle += step;
		i++;
	}
}

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
		}
		else
		{
			ray.wall = fabs(ray.dist.x);
			ray.nb.x += ray.dir.x;
			ray.dist.x = fabs(ray.dir.x * ray.nb.x / ray.theta_ang.x);
		}
	}
	return (ray);
}
