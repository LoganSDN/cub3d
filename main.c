/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:26:14 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/22 09:55:44 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "incl/cub3d.h"

void	routine(t_data *d)
{
	(void) d;
	// ft_rayscasting(d);
	draw_map(d);
	draw_player(d);
}

int	ft_error(char *str)
{
	ft_putstr_fd("\033[31;1;4m/!\\ Error /!\\\033[0m\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
	return (1);
}

int	check_extension(char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str && str[++i])
	{
		if (str[i] == '.')
			j = i;
	}
	str = str + j;
	if (ft_strncmp(str, ".cub", 4))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	d;
	int		fd;

	if (ac != 2)
		return (ft_error("Hum .. Something is missing"));
	if (check_extension(av[1]))
		return (ft_error("Bad extension. (Must be .cub)\n"));
	fd = open(av[1], O_DIRECTORY);
	if (fd > 0)
		return (ft_error("Map must be a file, not a directory. Hacker.\n"));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("Unable to open map\n"));
	init(&d, fd);
	routine(&d);
	mlx_hook(d.win_ptr, 2, 1L << 0, dial_key, &d);
	mlx_loop(d.mlx_ptr);
	free_all(&d);
	close(fd);
}
