/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:12:29 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/21 11:34:59 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (0);
}

void	free_all(t_data *d)
{
	free(d->tex.no_tex);
	free(d->tex.so_tex);
	free(d->tex.we_tex);
	free(d->tex.ea_tex);
	free_tab(d->map);
	// exit (0);
}

char	**join_and_split(t_data *d, int fd)
{	
	char	*str;
	char	*wtf;
	char	**map;
	int		i;

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
	i = -1;
	free(wtf);
	free(str);
	return (map);
}
