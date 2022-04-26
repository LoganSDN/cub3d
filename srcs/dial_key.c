/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dial_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emortier <emortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:01:41 by emortier          #+#    #+#             */
/*   Updated: 2022/04/25 18:56:18 by emortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	dial_key_move(int keycode, t_data *d)
{
	if (keycode == KEY_LEFT)
	{
		d->player_angle += 0.0500f;
		if (d->player_angle > 2 * M_PI)
			d->player_angle = 0;
		d->dir_player = v2f(cos(d->player_angle), sin(d->player_angle));
	}
	else if (keycode == KEY_RIGHT)
	{
		d->player_angle -= 0.0500f;
		if (d->player_angle < 0)
			d->player_angle += 2 * M_PI;
		d->dir_player = v2f(cos(d->player_angle), sin(d->player_angle));
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		d->player = v2f(d->player.x -(d->dir_player.x / 10) \
		, d->player.y + (d->dir_player.y / 10));
	else if (keycode == KEY_UP || keycode == KEY_W)
		d->player = v2f(d->player.x +(d->dir_player.x / 10) \
		, d->player.y - (d->dir_player.y / 10));
	ft_bzero(d->img.img_ptr, (HEIGHT * d->img.sl) + (WIDTH * d->img.bpp));
	ft_rayscasting(d);
	return (0);
}

int	dial_key(int keycode, t_data *d)
{
	if (keycode == KEY_ESC)
		exit(1);
	dial_key_move(keycode, d);
	return (0);
}
