/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:59:18 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/25 08:46:19 by lsidan           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../srcs/vector/vector.h"
# include "../libft/libft.h"
# include "key_map_azerty.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define WIDTH	720
# define HEIGHT	420

# define TABLE	"NSEW10 "

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
	void	*img;
	int		bpp;
	int		sl;
	int		endian;
	void	*ptr;
	int		width;
	int		height;
	char	*path;
}	t_data_tex;

typedef struct s_texture
{
	t_data_tex	no_tex;
	t_data_tex	so_tex;
	t_data_tex	we_tex;
	t_data_tex	ea_tex;
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

typedef struct s_img
{
	void	*img;
	void	*img_ptr;
	int		sl;
	int		endian;
	int		bpp;
}	t_img;

typedef struct s_data
{
	t_img	img;
	t_tex	tex;
	t_v2f	player;
	t_v2	ratio;
	t_v2f	dir_player;
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
int		only_one(char *str);
int		stop(char c, char *table);

//PROCESS
void	routine(t_data *d);

//UTILS
char	**join_and_split(t_data *d, int fd);
void	free_all(t_data *d);
int		free_tab(char **tab);
int		ft_error(char *str);

//INIT
void	init(t_data *d, int fd);

//DRAW
void	put_pxl_to_img(int x, int y, int color, t_data *d);
void	draw_map(t_data *d);
void	draw_square(t_data *d, int color, t_v2f map);
void	draw_player(t_data *d);
void	draw_line(t_data *d, t_v2 src, t_v2 dst, int c);
void	draw_line_f(t_data *d, t_v2 src, t_v2f dst, int c);
void	draw_angle(t_data *d, int len, t_v2f dir, int color);

//EVENT
int		dial_key(int keycode, t_data *d);
int		dial_key_move(int keycode, t_data *d);

//RAYCASTING
int		ft_isawall(t_data *d, t_ray ray);
t_ray	ft_ray(t_data *d, double angle );
void	ft_pos_in_map(t_data *d, t_ray ray, t_v2f *pos);
void	ft_relative_pos(t_ray *ray, t_data *d);
t_ray	ft_init_rays(t_data *d, double angle);
double	ft_get_theta(double angle);
void	ft_rayscasting(t_data *d);

#endif