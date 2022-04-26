/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:59:18 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/26 07:36:54 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../srcs/vector/vector.h"
# include "../libft/libft.h"
# include "key_map_qwerty.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define WIDTH	1440 / 2
# define HEIGHT 1170 / 2
# define FOV 	1.0471975512

# define TABLE	"NSEW10 "

typedef struct s_img
{
	void	*img;
	void	*img_ptr;
	int		sl;
	int		endian;
	int		bpp;
}	t_img;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}	t_rgb;

typedef union s_col
{
	t_rgb	rgb;
	int		value;
}	t_col;

typedef struct s_data_tex
{
	t_img	img;
	int		width;
	int		height;
	char	*path;
}	t_data_tex;

typedef struct s_texture
{
	t_data_tex	tex[4];
	t_col		floor_col;
	t_col		ceil_col;
}	t_tex;

typedef struct s_ray
{
	float	wall;
	t_v2f	pos;
	t_v2f	nb;
	t_v2f	dist;
	t_v2	dir;
	int		side;
	double	ray_angle;
	t_v2f	ray_dir;
	double	theta;
	t_v2f	theta_ang;
}	t_ray;

typedef struct s_data
{
	t_img	img;
	t_tex	tex;
	t_v2f	player;
	t_v2f	dir_player;
	t_ray	ray;
	int		nb_rays;
	double	player_angle;
	void	*win_ptr;
	void	*mlx_ptr;
	char	**map;
	int		map_height;
	int		map_len;
}	t_data;

//PARSING
void	get_desc(t_data *d);
/* Texture */
void	get_north(t_data *d, int i, int *j, int *order);
void	get_south(t_data *d, int i, int *j, int *order);
void	get_west(t_data *d, int i, int *j, int *order);
void	get_east(t_data *d, int i, int *j, int *order);
void	get_tex(t_data	*d, int i, int *j, int *order);
/* Colors */
void	get_color(t_data *d, int i, int *j, int *order);
void	get_floor(t_data *d, int i, int *j, int *order);
void	get_ceil(t_data *d, int i, int *j, int *order);
/* Map */
void	check_map(t_data *d, char **map, int *order);
int		check_border(t_data *d, char **map);
int		check_char(t_data *d, char **map);
/* Utils */
char	**add_space(char **old, int max, int nb_line);
char	*autocomplete(char *str, int x);
void	replace(char ***map);
int		count_digits(int nb);
int		stop(char c, char *table);
int		check_w_h(t_data *d);
int		check_corner(char **map, int i, int j, t_data *d);

//UTILS
char	**join_and_split(t_data *d, int fd);
void	free_all(t_data *d);
int		free_tab(char **tab);
int		ft_error(char *str);

//INIT
void	init(t_data *d, int fd);

//DRAW
void	put_pxl_to_img(int x, int y, int color, t_data *d);
void	draw_wall(t_data *d, int col, t_ray ray);
void	ft_put_texture(t_data *d, int col, t_v2 wall, t_ray ray);

//EVENT
int		dial_key(int keycode, t_data *d);
int		dial_key_move(int keycode, t_data *d);

//RAYCASTING
int		ft_isawall(t_data *d, t_ray *ray);
t_ray	ft_ray(t_data *d, double angle );
void	ft_pos_in_map(t_data *d, t_ray ray, t_v2f *pos);
void	ft_relative_pos(t_ray *ray, t_data *d);
t_ray	ft_init_rays(t_data *d, double angle);
double	ft_get_theta(double angle);
void	ft_rayscasting(t_data *d);

#endif