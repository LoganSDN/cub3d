/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emortier <emortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:41:00 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/22 16:00:09 by emortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	check_map(t_data *d, char **map)
{
	int		i;
	int		j;
	int		max;
	char	**new;

	i = -1;
	max = 0;
	while (map[++i])
		if (ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
	new = malloc(sizeof(char *) * (i + 1));
	if (!new)
		ft_error("Malloc crash. (Check your ram .. ?)");
	i = -1;
	while (map[++i])
	{
		new[i] = malloc(sizeof(char) * (max + 1));
		if (!new[i])
		{
			free_tab(new);
			free_tab(map);
			ft_error("Malloc crash. (Check your ram .. ?)");
		}
		new[i][max] = 0;
		ft_strlcpy(new[i], map[i], max + 1);
	}
	new[i] = 0;
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
	d->map_len = ft_strlen(new[0]);
	i = 0;
	while (new[i])
		d->map_height = i++;
	d->ratio = v2(WIDTH / d->map_len, HEIGHT / d->map_height);
	d->map_height++;
	i = -1;
	if (check_border(d, new) || check_char(d, new))
		ft_putstr_fd("Error\n", 2);
	replace(&new);
	free_tab(d->map);
	d->map = new;
	// while (new[++i])
	// 	dprintf(1, "%s\n", new[i]);
}
