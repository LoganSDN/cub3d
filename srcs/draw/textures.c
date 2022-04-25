/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emortier <emortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:35:48 by emortier          #+#    #+#             */
/*   Updated: 2022/04/25 17:40:35 by emortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	draw_wall(t_data *d, int col, t_ray ray)
{
	int		i;
	int		wall_height;
	t_v2	wall;

	i = -1;
	wall_height = HEIGHT / ray.wall;
	wall = v2((HEIGHT - wall_height) / 2, (HEIGHT + wall_height) / 2);
	while (++i <= wall.x)
	{
		put_pxl_to_img(WIDTH - col, i, d->tex.ceil_col.value, d);
		put_pxl_to_img(WIDTH - col, wall.y + i, d->tex.floor_col.value, d);
	}
	ft_put_texture(d, col, wall, ray);
}

int	ft_choose_tex(t_ray ray)
{
	int	choose ;

	if (ray.side == 1)
		if (ray.dir.y > 0)
			choose = 0;
	else
			choose = 2;
	else
		if (ray.dir.x < 0)
			choose = 1;
	else
			choose = 3;
	return (choose);
}

void	ft_put_texture(t_data *d, int col, t_v2 wall, t_ray ray)
{
	int	z;
	int	i;
	int	color;
	int	size;
	int	choose;

	size = HEIGHT / ray.wall;
	z = 0;
	i = wall.x;
	while (i < wall.y)
	{
		choose = ft_choose_tex(ray);
		z = (i - wall.x) * d->tex.tex[choose].width / size;
		if (choose == 0 || choose == 2)
			color = *(int *)(d->tex.tex[choose].img.img_ptr + \
			(((d->tex.tex[choose].img.sl * z) + ((int)(ray.pos.x * \
			d->tex.tex[choose].width) * d->tex.tex[choose].img.bpp))));
		else
			color = *(int *)(d->tex.tex[choose].img.img_ptr + \
			(((d->tex.tex[choose].img.sl * z) + ((int)(ray.pos.y * \
			d->tex.tex[choose].width) * d->tex.tex[choose].img.bpp))));
		put_pxl_to_img(WIDTH - col, i, color, d);
		i++;
	}
}
