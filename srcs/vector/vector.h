/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:05:50 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/13 13:45:32 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_v2
{
	int		x;
	int		y;
}	t_v2;

typedef struct s_v2f
{
	float		x;
	float		y;
}	t_v2f;

typedef struct s_v2d
{
	double		x;
	double		y;
}	t_v2d;

t_v2	v2(int x, int y);
t_v2f	v2f(float x, float y);
t_v2d	v2d(double x, double y);

#endif