#include "fdf.h"

void	map_range(t_map *map, t_mappoint **array)
{
	int	i;
	int	j;

	init_range(&map->range);
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			map->range.x_min = ft_min(map->range.x_min, array[i][j].x);
			map->range.x_max = ft_max(map->range.x_max, array[i][j].x);
			map->range.y_min = ft_min(map->range.y_min, array[i][j].y);
			map->range.y_max = ft_max(map->range.y_max, array[i][j].y);
			map->range.z_min = ft_min(map->range.z_min, array[i][j].z);
			map->range.z_max = ft_max(map->range.z_max, array[i][j].z);
			map->range.color_min = \
						ft_min(map->range.color_min, array[i][j].color);
			map->range.color_max = \
						ft_max(map->range.color_max, array[i][j].color);
			j++;
		}
		i++;
	}
}

void	set_scale(t_map *map)
{
	int	range_max;

	range_max = ft_max(map->row, map->col);
	range_max = ft_max(range_max, map->range.z_max - map->range.z_min);
	if (range_max == map->row)
		map->scale = (double)(HEIGHT / 2) / (double)range_max;
	else if (range_max == map->col)
		map->scale = (double)(WIDTH / 2) / (double)range_max;
	else
		map->scale = (double)(HEIGHT) / (double)range_max;
	map->scale = map->scale * 3 / 4;
}

void	scale_points(t_map *map)
{
	int		i;
	int		j;

	map_range(map, map->array);
	set_scale(map);
	if ((int)map->scale == 0)
		return ;
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			map->array[i][j].x *= (int)map->scale;
			map->array[i][j].y *= (int)map->scale;
			map->array[i][j].z *= (int)map->scale;
			j++;
		}
		i++;
	}
}

void	pos_set(t_map *map)
{
	map->pos.x = (WIDTH / 2) - (map->range.x_max + map->range.x_min) / 2;
	map->pos.y = (HEIGHT / 2) - (map->range.y_max + map->range.y_min) / 2;
}

void	repos_xy(t_map *map, t_mappoint **array)
{
	int		i;
	int		j;

	map_range(map, array);
	pos_set(map);
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			array[i][j].x += map->pos.x;
			array[i][j].y += map->pos.y;
			j++;
		}
		i++;
	}
}
