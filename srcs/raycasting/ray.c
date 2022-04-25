/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emortier <emortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:24:35 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/25 17:40:45 by emortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	ft_fixeye(t_ray *ray, double angle);

void	ft_rayscasting(t_data *d)
{
	double	angle;
	double	step;
	int		i;
	t_ray	ray;

	i = 0;
	step = FOV / d->nb_rays;
	while (i <= d->nb_rays)
	{
		angle = fmod((d->player_angle - (FOV / 2)) + step * i, 2 * M_PI);
		ray = ft_ray(d, angle);
		ft_fixeye(&ray, d->player_angle - angle);
		draw_wall(d, i, ray);
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

void	ft_fixeye(t_ray *ray, double angle)
{
	double	theta;

	theta = fmod(fabs(angle), 2 * M_PI);
	if ((*ray).side == 1)
		(*ray).wall = (*ray).wall * cos(theta);
	else
		(*ray).wall = (*ray).wall * cos(theta);
}
