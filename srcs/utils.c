/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:12:29 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/26 09:17:31 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab && tab[++i])
	{
		if (tab[i])
			free(tab[i]);
	}
	free(tab);
	return (0);
}

void	free_all(t_data *d)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (d->tex.tex[i].img.img)
			mlx_destroy_image(d->mlx_ptr, d->tex.tex[i].img.img);
	}
	if (d->mlx_ptr && d->img.img)
	{
		mlx_destroy_image(d->mlx_ptr, d->img.img);
		mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	}
	if (d->map)
		free_tab(d->map);
}

char	**join_and_split(t_data *d, int fd)
{	
	char	*str;
	char	*wtf;
	char	**map;

	(void) d;
	str = get_next_line(fd);
	wtf = ft_strdup("");
	while (str)
	{
		wtf = ft_strjoin(wtf, str);
		free(str);
		str = get_next_line(fd);
	}
	map = ft_split(wtf, '\n');
	free(wtf);
	free(str);
	return (map);
}
