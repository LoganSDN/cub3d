/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emortier <emortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:26:14 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/21 14:41:25 by emortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/cub3d.h"

void	routine(t_data *d)
{
	(void) d;
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
	fd = open("maps/subj.cub", O_RDONLY);
	init(&d, fd);
	dprintf(2,"playerx= %d ,playery = %d\n",d.player.x, d.player.y);
	routine(&d);
	mlx_hook(d.win_ptr, 2, 1L << 0, dial_key, &d);
	mlx_loop(d.mlx_ptr);
	free_all(&d);
	close(fd);
}
