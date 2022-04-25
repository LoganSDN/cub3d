/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emortier <emortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:37:12 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/25 16:56:54 by emortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	put_pxl_to_img(int x, int y, int color, t_data *d)
{
	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
		*(int *)(d->img.img_ptr + \
		(((d->img.sl * y) + \
		(x * d->img.bpp)))) = color;
}
