/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emortier <emortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 08:50:36 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/22 15:19:38 by emortier         ###   ########.fr       */
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

int	check_char(t_data *d, char **map)
{
	int		i;
	int		j;
	t_v2	pos;
	int		count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && \
				map[i][j] != 'N' && map[i][j] != 'S' && \
				map[i][j] != 'E' && map[i][j] != 'W' && !ft_isspace(map[i][j]))
				ft_error("You slip an unrecognized char. You tricky boy.\n");
			if ((map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'W' || map[i][j] == 'E'))
			{
				pos = v2(j, i);
				d->player = v2f(j + 0.5, i + 0.5);
				spawn_angle(d, map, pos);
				count++;
			}
		}
	}
	if (count > 1 || !count)
	{
		if (count > 1)
			ft_error("Too many players ..(Multi not supported)\n");
		else
			ft_error("So you want to play, without a player ? Ratio.\n");
		return (1);
	}
	return (0);
}

int	check_border(t_data *d, char **map)
{
	int	i;
	int	j;

	(void) d;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] && map[i][j] == '0')
			{
				if ((map[i - 1][j] && map[i - 1][j] == ' ') || \
					(map[i + 1][j] && map[i + 1][j] == ' ') || \
					(map[i][j + 1] && map[i][j + 1] == ' ') || \
					(map[i][j - 1] && map[i][j - 1] == ' '))
				{
					ft_printf("Error in [%d][%d] -> %c\n", i, j, map[i][j]);
					ft_error("");
					return (1);
				}
			}
		}
	}
	return (0);
}
