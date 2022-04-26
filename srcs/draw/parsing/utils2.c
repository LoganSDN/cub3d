/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emortier <emortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:01:23 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/26 10:04:39 by emortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

#define TAB "10NSEW" 

int	count_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	check_w_h(t_data *d)
{
	int	width;
	int	height;

	width = d->tex.tex[0].width;
	height = d->tex.tex[0].height;
	if (width != d->tex.tex[1].width || width != d->tex.tex[2].width || \
		width != d->tex.tex[3].width)
		return (1);
	if (height != d->tex.tex[1].height || height != d->tex.tex[2].height || \
		height != d->tex.tex[3].height)
		return (1);
	return (0);
}

int	check_corner(char **map, int i, int j, t_data *d)
{
	int	ln;

	(void) d;
	ln = count_line(map);
	if (j != ft_strlen(map[i]) && map[i][j + 1] && map[i][j + 1] == '0')
		return (0);
	if (j && map[i][j - 1] && map[i][j - 1] == '0')
		return (0);
	if (i && map[i - 1][j] && map[i - 1][j] == '0')
		return (0);
	if (i != ln - 1 && map[i + 1][j] && map[i + 1][j] == '0')
		return (0);
	if (j != ft_strlen(map[i]) && i != 0 && \
		map[i - 1][j + 1] && map[i - 1][j + 1] == '0')
		return (0);
	if (j && i && map[i - 1][j - 1] && map[i - 1][j - 1] == '0')
		return (0);
	if (i != ln && j != ft_strlen(map[i]) && map[i + 1] \
		&& map[i + 1][j + 1] && map[i + 1][j + 1] == '0')
		return (0);
	if (i != ln - 1 && j && map[i + 1][j - 1] && map[i + 1][j - 1] == '0')
		return (0);
	return (1);
}

void	ft_check_surroundings(t_data *d, char **map, int y, int x)
{
	int	i;
	int	j;

	j = 1;
	while (j >= -1)
	{
		i = 1;
		while (map[y - j][x - i] && i >= -1)
		{
			if (map[y - j][x - i] == ' ')
				ft_error("Character not surrounded \
				by viable environement, better be on Mars at this point", d);
			i--;
		}
		j--;
	}
}
