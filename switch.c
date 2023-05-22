/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:09:23 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/22 15:09:24 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_iso(t_map *map)
{
	ft_bzero(map->img->addr, WIDTH * HEIGHT * (map->img->bits_per_pixel / 8));
	init_iso(map);
	ft_isometric_projection(map);
	ft_rotation(map, map->iso);
	zoom_points(map, map->iso);
	repos_xy(map, map->iso);
	move_points(map, map->iso);
	draw_image(map, map->iso);
	mlx_put_image_to_window(map->data->mlx_ptr, map->data->win_ptr, \
							map->img->img, 0, 0);
}

static void	malloc_para(t_map *map)
{
	int			i;

	map->para = (t_mappoint **)malloc(sizeof(t_mappoint *) * map->row);
	if (map->para == NULL)
	{
		free_map(map, map->row);
		exit(1);
	}
	i = 0;
	while (i < map->row)
	{
		map->para[i] = (t_mappoint *)malloc(sizeof(t_mappoint) * map->col);
		if (map->para[i] == NULL)
		{
			free_para(map, i);
			free_map(map, map->row);
			exit(1);
		}
		i++;
	}
}

static void	init_para(t_map *map)
{
	int			i;
	int			j;

	if (map->para == NULL)
		malloc_para(map);
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			map->para[i][j].x = map->array[i][j].x;
			map->para[i][j].y = map->array[i][j].y;
			map->para[i][j].z = map->array[i][j].z;
			map->para[i][j].color = map->array[i][j].color;
			j++;
		}
		i++;
	}
}

void	draw_para(t_map *map)
{
	ft_bzero(map->img->addr, WIDTH * HEIGHT * (map->img->bits_per_pixel / 8));
	init_para(map);
	repos_xy(map, map->para);
	draw_image(map, map->para);
	mlx_put_image_to_window(map->data->mlx_ptr, map->data->win_ptr, \
							map->img->img, 0, 0);
}
