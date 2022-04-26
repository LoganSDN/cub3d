/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 08:50:36 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/26 11:24:08 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	spawn_angle(t_data *d, char **map, t_v2 pos)
{
	if (map[pos.y][pos.x] == 'N')
		d->player_angle = M_PI_2;
	else if (map[pos.y][pos.x] == 'S')
		d->player_angle = 3 * M_PI_2;
	else if (map[pos.y][pos.x] == 'W')
		d->player_angle = M_PI;
	else if (map[pos.y][pos.x] == 'E')
		d->player_angle = 0;
}

int	check_count(int count, t_data *d)
{
	if (count > 1 || !count)
	{
		if (count > 1)
			ft_error("Too many players ..(Multi not supported)\n", d);
		else
			ft_error("So you want to play, without a player ? Ratio.\n", d);
		return (1);
	}
	return (0);
}

void	check_forbidden_char(char **map, int i, int j, t_data *d)
{
	if (map[i][j] != '0' && map[i][j] != '1' && \
	map[i][j] != 'N' && map[i][j] != 'S' && \
	map[i][j] != 'E' && map[i][j] != 'W' && !ft_isspace(map[i][j]))
		ft_error("You slip an unrecognized char. You tricky boy.\n", d);
}

int	check_char(t_data *d, char **map)
{
	t_v2	q;
	t_v2	pos;
	int		count;

	q = v2(-1, -1);
	count = 0;
	if (!map)
		ft_error("Malloc crash. (Check your ram .. ?)\n", d);
	while (map[++q.x])
	{
		q.y = -1;
		while (map[q.x][++q.y])
		{
			check_forbidden_char(map, q.x, q.y, d);
			if (ft_strchr("NSEW", map[q.x][q.y]) != NULL)
			{
				ft_check_surroundings(d, map, q.x, q.y);
				pos = v2(q.y, q.x);
				d->player = v2f(q.y + 0.5, q.x + 0.5);
				spawn_angle(d, map, pos);
				count++;
			}
		}
	}
	return (check_count(count, d));
}

int	check_border(t_data *d, char **map)
{
	int	i;
	int	j;

	(void) d;
	i = -1;
	if (!map)
		ft_error("Malloc crash. (Check your ram .. ?)\n", d);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == ' ' && !check_corner(map, i, j, d))
			{
				ft_printf("Error in [%d][%d]", i, j);
				ft_error("", d);
				return (1);
			}
		}
	}
	return (0);
}
