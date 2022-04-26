/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:41:00 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/26 11:04:45 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

char	**cpy_map(char **map, int *max, char ***new, t_data *d)
{
	int		i;

	i = -1;
	(*max) = 0;
	while (map[++i])
		if (ft_strlen(map[i]) > (*max))
			(*max) = ft_strlen(map[i]);
	(*new) = malloc(sizeof(char *) * (i + 1));
	if (!(*new))
		ft_error("Malloc crash. (Check your ram .. ?)", d);
	i = -1;
	while (map[++i])
	{
		(*new)[i] = malloc(sizeof(char) * ((*max) + 1));
		if (!(*new)[i])
		{
			free_tab((*new));
			free_tab(map);
			ft_error("Malloc crash. (Check your ram .. ?)", d);
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
}

void	check_map(t_data *d, char **map, int *order)
{
	int		i;
	int		j;
	int		max;
	char	**new;

	cpy_map(map, &max, &new, d);
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
		ft_error("Parse error\n", d);
	replace(&new);
	init_map_var(d, new);
	free_tab(d->map);
	d->map = new;
	(*order)++;
}

void	skip_space(t_data *d, int i, int *j, int p_s)
{
	int	c;

	c = 0;
	if (p_s)
		while (ft_isspace(d->map[i][*j]))
			(*j)++;
	else
	{
		while (ft_isspace(d->map[i][*j]) || d->map[i][*j] == ',')
		{
			if (d->map[i][*j] == ',')
				c++;
			(*j)++;
		}
	}
	if (c > 1)
		ft_error("Too may coma\n", d);
}

void	check_color_count(t_data *d, int i, int *j)
{
	skip_space(d, i, j, 0);
	if (ft_atoi(d->map[i] + (*j)) >= 0)
		ft_error("Wrong number of color\n", d);
	if (d->tex.count != 3)
		ft_error("Wrong number of color667\n", d);
}
