# cub3d
Doom-like in C - First ray-casting engine 


		if (ray.side == 1)
		{
			color = *(int *)(d->img.img_ptr + (((d->tex.tex[0].img.sl * z) + ((int) ray.pos.x * 32 * d->tex.tex[0].img.bpp))));
			put_pxl_to_img(col, i, d->tex.tex[0].img.img_ptr + color, d);
		}
		else
		{
			color = *(int *)(d->img.img_ptr + (((d->tex.tex[1].img.sl * z) + ((int) ray.pos.y * 32 * d->tex.tex[1].img.bpp))));
			put_pxl_to_img(col, i, d->tex.tex[1].img.img_ptr + color, d);