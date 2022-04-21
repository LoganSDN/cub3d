/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:26:14 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/21 10:19:03 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "incl/cub3d.h"

void	routine(t_data *d)
{
	draw_map(d);
	draw_player(d);
}

int	main(int ac, char **av)
{
	t_data	d;
	int		fd;
	int		i;

	(void) ac;
	(void) av;
	i = -1;
	fd = open("maps/first.cub", O_RDONLY);
	init(&d, fd);
	dprintf(1, "NO = %s\n", d.tex.no_tex);
	dprintf(1, "SO = %s\n", d.tex.so_tex);
	dprintf(1, "WE = %s\n", d.tex.we_tex);
	dprintf(1, "EA = %s\n", d.tex.ea_tex);
	dprintf(1, "F = %d", d.tex.floor_col.rgb.r);
	dprintf(1, " %d", d.tex.floor_col.rgb.g);
	dprintf(1, " %d -> %d\n", d.tex.floor_col.rgb.b, d.tex.floor_col.value);
	dprintf(1, "C = %d", d.tex.ceil_col.rgb.r);
	dprintf(1, " %d", d.tex.ceil_col.rgb.g);
	dprintf(1, " %d -> %d\n", d.tex.ceil_col.rgb.b, d.tex.ceil_col.value);
	dprintf(1, "player.x = %d\nplayer.y = %d\n", d.player.x, d.player.y);
	// routine(&d);
	// mlx_hook(d.win_ptr, 2, 1L << 0, dial_key, &d);
	// mlx_hook(d.win_ptr, 17, 1L << 2, ft_close, &d);
	// mlx_loop(d.mlx_ptr);
	i = -1;
	while (d.map[++i])
		dprintf(1, "%s\n", d.map[i]);
	free_all(&d);
	close(fd);
}
