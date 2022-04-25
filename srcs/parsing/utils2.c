/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:01:23 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/25 11:21:52 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

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
