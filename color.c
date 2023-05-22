/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:07:26 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/22 15:07:28 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	now_position(int pre, int now, int extent)
{
	if (extent == 0)
		return (1.0);
	return ((double)(now - pre) / (double)extent);
}

static int	get_color(int pre, int next, double now_pos)
{
	return ((int)((1 - now_pos) * pre + now_pos * next));
}

int	now_color(t_mappoint pre, t_mappoint now, t_mappoint next, t_map *map)
{
	int		red;
	int		green;
	int		blue;
	double	now_pos;
	t_point	extent;

	extent.x = ft_abs(next.x - pre.x);
	extent.y = ft_abs(next.y - pre.y);
	if (now.color == next.color || map->color_mode == NORMAL)
		return (now.color);
	if (extent.x > extent.y)
		now_pos = now_position(pre.x, now.x, extent.x);
	else
		now_pos = now_position(pre.y, now.y, extent.y);
	red = get_color((pre.color >> 16) & 0xFF, \
					(next.color >> 16) & 0xFF, \
					now_pos);
	green = get_color((pre.color >> 8) & 0xFF, \
					(next.color >> 8) & 0xFF, \
					now_pos);
	blue = get_color(pre.color & 0xFF, \
					next.color & 0xFF, \
					now_pos);
	return ((red << 16) | (green << 8) | blue);
}
