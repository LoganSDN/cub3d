/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 08:44:28 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/21 11:33:56 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	count_digits(int nb)
{
	int	i;

	i = 0;
	if (!nb)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	**add_space(char **old, int max, int nb_line)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	j = 0;
	new = malloc(sizeof(char **) * (nb_line + 3));
	if (new)
	{
		new[0] = malloc(sizeof(char) * (max + 1));
		new[0] = autocomplete(new[0], max + 2);
		while (++i <= nb_line)
		{
			new[i] = nofree_strjoin(" ", old[j++]);
			new[i] = autocomplete(new[i], max + 2);
		}
		new[i] = calloc((max + 1), sizeof(char));
		if (new[i])
			new[i] = autocomplete(new[i], max + 2);
		if (new[i + 1])
			new[i + 1] = 0;
	}
	free_tab(old);
	return (new);
}

char	*autocomplete(char *str, int x)
{
	int		len;
	int		i;
	char	*tmp;
	char	*tmp2;

	i = -1;
	len = ft_strlen(str);
	tmp = malloc(sizeof(char) * (x - len) + 1);
	while (++i < x - len)
		tmp[i] = ' ';
	tmp[i] = 0;
	tmp2 = ft_strjoin(str, tmp);
	free(tmp);
	return (tmp2);
}

int	stop(char c, char *table)
{
	int	i;

	i = -1;
	while (table && table[++i])
	{
		if (table[i] != c)
			return (1);
	}
	return (0);
}

void	replace(char ***map)
{
	int	i;
	int	j;

	i = -1;
	while ((*map)[++i])
	{
		j = -1;
		while ((*map)[i][++j])
			if ((*map)[i][j] == ' ')
				(*map)[i][j] = '1';
	}
}
