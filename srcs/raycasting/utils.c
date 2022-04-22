/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:06:57 by emortier          #+#    #+#             */
/*   Updated: 2022/04/22 14:47:16 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	ft_relative_pos(t_ray *ray, t_data *d)
{
	if (ray->ray_dir.y < 0)
	{
		(*ray).dir.y = 1;
		(*ray).nb.y = 1.f - ((float)(d->player.y % d->ratio.y) \
		/ (float)d->ratio.y);
	}
	else
	{
		(*ray).dir.y = -1;
		(*ray).nb.y = ((float)(d->player.y % d->ratio.y) \
		/ (float)d->ratio.y) * (float)(*ray).dir.y;
	}
	if (ray->ray_dir.x < 0)
	{
		(*ray).dir.x = -1;
		(*ray).nb.x = ((float)(d->player.x % d->ratio.x) \
		/ (float)d->ratio.x) * (float)(*ray).dir.x;
	}
	else
	{
		(*ray).dir.x = 1;
		(*ray).nb.x = 1.f - ((float)(d->player.x % d->ratio.x) \
		/ (float)d->ratio.x);
	}
}

t_ray	ft_init_rays(t_data *d, double angle)
{
	t_ray	ray;

	ray.ray_angle = angle;
	ray.ray_dir = v2f(cos(angle), sin(angle));
	ray.theta = fabs(ft_get_theta(angle));
	ray.theta_ang = v2f(cos(ray.theta), sin (-ray.theta));
	ray.wall = 0;
	ft_relative_pos(&ray, d);
	ray.dist.y = fabs(ray.dir.y * ray.nb.y / ray.theta_ang.y);
	ray.dist.x = fabs(ray.dir.x * ray.nb.x / ray.theta_ang.x);
	return (ray);
}

void	ft_pos_in_map(t_data *d, t_ray ray, t_v2 *pos)
{
	if (ray.dist.x < ray.dist.y)
	{
		(*pos).x = (d->player.x + \
		(ray.nb.x * d->ratio.x) + ray.dir.x) / d->ratio.x;
		if ((ray.ray_dir.x > 0 && ray.ray_dir.y < 0) \
		|| (ray.ray_dir.x < 0 && ray.ray_dir.y > 0))
			(*pos).y = (d->player.y + \
			(tan(ray.theta) * ray.nb.x * d->ratio.y)) / d->ratio.y;
		else
			(*pos).y = (d->player.y + \
			(tan(-ray.theta) * ray.nb.x * d->ratio.y)) / d->ratio.y;
	}
	else
	{
		if ((ray.ray_dir.x > 0 && ray.ray_dir.y < 0) || \
		(ray.ray_dir.x < 0 && ray.ray_dir.y > 0))
			(*pos).x = (d->player.x + \
		((ray.nb.y / tan(ray.theta)) * d->ratio.x)) / d->ratio.x;
		else
			(*pos).x = (d->player.x + ((ray.nb.y / tan(-ray.theta)) \
			* d->ratio.x)) / d->ratio.x;
		(*pos).y = (d->player.y + (ray.nb.y * d->ratio.y) + ray.dir.y) \
		/ d->ratio.y;
	}
}

int	ft_isawall(t_data *d, t_ray ray)
{
	t_v2	pos;

	ft_pos_in_map(d, ray, &pos);
	if (pos.x >= 0 && pos.y >= 0 && pos.x <= d->map_len && \
		pos.y <= d->map_height && d->map[pos.y][pos.x] == '1')
	{
		ray.pos = pos;
		return (1);
	}
	return (0);
}

double	ft_get_theta(double angle)
{
	if (angle > M_PI_2 && angle <= M_PI)
		return (M_PI - angle);
	if (angle > M_PI && angle <= 3 * M_PI_2)
		return (angle - M_PI);
	if (angle >= 3 * M_PI_2)
		return (2 * M_PI - angle);
	return (angle);
}
