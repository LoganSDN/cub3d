/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsidan <lsidan@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:03:35 by lsidan            #+#    #+#             */
/*   Updated: 2022/04/13 13:08:35 by lsidan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_v2	v2(int x, int y)
{
	t_v2	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_v2f	v2f(float x, float y)
{
	t_v2f	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_v2d	v2d(double x, double y)
{
	t_v2d	v;

	v.x = x;
	v.y = y;
	return (v);
}
