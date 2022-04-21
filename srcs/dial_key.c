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
		d->player.x -= (int)(d->dir_player.x * 10);
		d->player.y += (int)(d->dir_player.y * 10);
	}
	else if (keycode == KEY_UP)
	{
		d->player.x += (int)(d->dir_player.x * 10);
		d->player.y -= (int)(d->dir_player.y * 10);
	}
	routine(d);
	return (0);
}

int	dial_key(int keycode, t_data *d)
{
	dprintf(1, "%d\n", keycode);
	if (keycode == KEY_ESC)
		exit(1);
	dial_key_move(keycode, d);
	return (0);
}
