#include "../incl/cub3d.h"

int	dial_key_move(int keycode, t_data *d)
{
	if (keycode == KEY_LEFT)
	{
		d->player_angle += 0.1f;
		if (d->player_angle > 2 * M_PI)
			d->player_angle = 0;
		d->dir_player.x = cos(d->player_angle);
		d->dir_player.y = sin(d->player_angle);
	}
	else if (keycode == KEY_RIGHT)
	{
		d->player_angle -= 0.1f;
		if (d->player_angle < 0)
			d->player_angle += 2 * M_PI;
		d->dir_player.x = cos(d->player_angle);
		d->dir_player.y = sin(d->player_angle);
	}
	else if (keycode == KEY_DOWN)
	{
		d->player.x -= (int)(d->dir_player.x * 5);
		d->player.y += (int)(d->dir_player.y * 5);
	}
	else if (keycode == KEY_UP)
	{
		d->player.x += (int)(d->dir_player.x * 5);
		d->player.y -= (int)(d->dir_player.y * 5);
	}
	// else if (keycode == KEY_MINUS && d->nb_rays > 50)
	// 	d->nb_rays -= 2;
	// else if (keycode == KEY_PLUS)
	// 	d->nb_rays += 2;
	ft_bzero(d->img.img_ptr, (HEIGHT * d->img.sl) + (WIDTH * d->img.bpp));
	routine(d);
	return (0);
}

int	dial_key(int keycode, t_data *d)
{
	if (keycode == KEY_ESC)
		exit(1);
	dial_key_move(keycode, d);
	return (0);
}
