/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:26:14 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/26 09:15:16 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "incl/cub3d.h"

int	ft_error(char *str, t_data *d)
{
	ft_putstr_fd("\033[31;1;4m/!\\ Error /!\\\033[0m\n", 2);
	ft_putstr_fd(str, 2);
	free_all(d);
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

void	null(t_data *d)
{
	int	i;

	i = -1;
	d->img.img = NULL;
	d->img.img_ptr = NULL;
	d->mlx_ptr = NULL;
	d->win_ptr = NULL;
	d->map = NULL;
	while (++i < 4)
	{
		d->tex.tex[i].path = NULL;
		d->tex.tex[i].img.img = NULL;
		d->tex.tex[i].img.img_ptr = NULL;
	}
}

int	bye(t_data *d)
{
	ft_putstr_fd("bye\n", 2);
	free_all(d);
	exit (0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	d;
	int		fd;

	null(&d);
	if (ac != 2)
		return (ft_error("Hum .. Something is missing", &d));
	if (check_extension(av[1]))
		return (ft_error("Bad extension. (Must be .cub)\n", &d));
	fd = open(av[1], O_DIRECTORY);
	if (fd > 0)
		return (ft_error("Map must be a file, not a directory. Hacker.\n", &d));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("Unable to open map\n", &d));
	init(&d, fd);
	ft_rayscasting(&d);
	mlx_hook(d.win_ptr, 2, 1L << 0, dial_key, &d);
	mlx_hook(d.win_ptr, 17, 1L << 2, bye, &d);
	mlx_loop(d.mlx_ptr);
	free_all(&d);
	close(fd);
}
