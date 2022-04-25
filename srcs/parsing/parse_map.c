/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:41:00 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/25 14:36:19 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

char	**cpy_map(char **map, int *max, char ***new)
{
	int		i;

	i = -1;
	(*max) = 0;
	while (map[++i])
		if (ft_strlen(map[i]) > (*max))
			(*max) = ft_strlen(map[i]);
	(*new) = malloc(sizeof(char *) * (i + 1));
	if (!(*new))
		ft_error("Malloc crash. (Check your ram .. ?)");
	i = -1;
	while (map[++i])
	{
		(*new)[i] = malloc(sizeof(char) * ((*max) + 1));
		if (!(*new)[i])
		{
			free_tab((*new));
			free_tab(map);
			ft_error("Malloc crash. (Check your ram .. ?)");
		}
		(*new)[i][(*max)] = 0;
		ft_strlcpy((*new)[i], map[i], (*max) + 1);
	}
	(*new)[i] = 0;
	return ((*new));
}

void	init_map_var(t_data *d, char **map)
{
	int	i;

	i = 0;
	d->map_len = ft_strlen(map[0]);
	while (map[i])
		d->map_height = i++;
	d->map_height++;
	d->ratio = v2(WIDTH / d->map_len, HEIGHT / d->map_height);
}

void	check_map(t_data *d, char **map, int *order)
{
	int		i;
	int		j;
	int		max;
	char	**new;

	cpy_map(map, &max, &new);
	i = -1;
	while (new[++i])
	{
		j = 0;
		while (new[i][j])
			j++;
		if (j < max)
			while (j < max)
				new[i][j++] = ' ';
	}
	new = add_space(new, max, i);
	i = -1;
	if (check_border(d, new) || check_char(d, new))
		ft_error("Parse error\n");
	replace(&new);
	init_map_var(d, new);
	free_tab(d->map);
	d->map = new;
	(*order)++;
}
