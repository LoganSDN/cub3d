/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:06:57 by emortier          #+#    #+#             */
/*   Updated: 2022/04/25 10:32:51 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	ft_relative_pos(t_ray *ray, t_data *d)
{
	if (ray->ray_dir.y < 0)
	{
		(*ray).dir.y = 1;
		(*ray).nb.y = 1.f - fmod(d->player.y, 1);
	}
	else
	{
		(*ray).dir.y = -1;
		(*ray).nb.y = fmod(d->player.y, 1) * (float)(*ray).dir.y;
	}
	if (ray->ray_dir.x < 0)
	{
		(*ray).dir.x = -1;
		(*ray).nb.x = (float) fmod(d->player.x, 1) * (float)(*ray).dir.x;
	}
	else
	{
		(*ray).dir.x = 1;
		(*ray).nb.x = 1.f - fmod(d->player.x, 1);
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

void	ft_pos_in_map(t_data *d, t_ray ray, t_v2f *pos)
{
	if (ray.dist.x < ray.dist.y)
	{
		(*pos).x = (d->player.x + ray.nb.x + 0.01f * ray.dir.x);
		if ((ray.ray_dir.x > 0 && ray.ray_dir.y < 0) \
		|| (ray.ray_dir.x < 0 && ray.ray_dir.y > 0))
			(*pos).y = (d->player.y + (tan(ray.theta) * ray.nb.x));
		else
			(*pos).y = d->player.y + (tan(-ray.theta) * ray.nb.x);
	}
	else
	{
		if ((ray.ray_dir.x > 0 && ray.ray_dir.y < 0) || \
		(ray.ray_dir.x < 0 && ray.ray_dir.y > 0))
			(*pos).x = d->player.x + (ray.nb.y / tan(ray.theta));
		else
			(*pos).x = d->player.x + (ray.nb.y / tan(-ray.theta));
		(*pos).y = d->player.y + ray.nb.y + 0.01f * ray.dir.y;
	}
}

int	ft_isawall(t_data *d, t_ray *ray)
{
	t_v2f	pos;

	ft_pos_in_map(d, (*ray), &pos);
	if (pos.x >= 0 && pos.y >= 0 && pos.x <= d->map_len && \
		pos.y <= d->map_height && d->map[(int)pos.y][(int)pos.x] == '1')
	{
		(*ray).pos.x = fmod(pos.x, 1);
		(*ray).pos.y = fmod(pos.y, 1);
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
