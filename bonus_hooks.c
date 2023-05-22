/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masa <masa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:08:45 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/22 19:08:08 by masa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_points(t_map *map, t_mappoint **array)
{
	int	i;
	int	j;

	if (map->zoom <= 0)
		return ;
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			array[i][j].x *= map->zoom;
			array[i][j].y *= map->zoom;
			array[i][j].z *= map->zoom;
			j++;
		}
		i++;
	}
}

void	move_points(t_map *map, t_mappoint **array)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			array[i][j].x += map->move_x;
			array[i][j].y += map->move_y;
			j++;
		}
		i++;
	}
}

void	ft_zoom(int button, t_map *map)
{
	if (button == 4)
		map->zoom *= 0.97;
	else if (button == 5)
		map->zoom *= 1.03;
	draw_iso(map);
}

void	ft_move(int keycode, t_map *map)
{
	if (keycode == XK_Left)
		map->move_x -= 50;
	else if (keycode == XK_Right)
		map->move_x += 50;
	else if (keycode == XK_Up)
		map->move_y -= 50;
	else if (keycode == XK_Down)
		map->move_y += 50;
	draw_iso(map);
}

void	ft_rotate(int keycode, t_map *map)
{
	if (keycode == XK_comma)
	{
		if (map->axis == X)
			map->theeta_x -= 15.0;
		else if (map->axis == Y)
			map->theeta_y -= 15.0;
		else if (map->axis == Z)
			map->theeta_z -= 15.0;
	}
	else if (keycode == XK_period)
	{
		if (map->axis == X)
			map->theeta_x += 15.0;
		else if (map->axis == Y)
			map->theeta_y += 15.0;
		else if (map->axis == Z)
			map->theeta_z += 15.0;
	}
	draw_iso(map);
}
