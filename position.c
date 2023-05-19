#include "fdf.h"

void	map_range(t_map *map, int x, int y, int z)
{
	if (map->range.x_min > x)
		map->range.x_min = x;
	if (map->range.x_max < x)
		map->range.x_max = x;
	if (map->range.y_min > y)
		map->range.y_min = y;
	if (map->range.y_max < y)
		map->range.y_max = y;
	if (map->range.z_min > z)
		map->range.z_min = z;
	if (map->range.z_max < z)
		map->range.z_max = z;
}

void	color_range(t_map *map, int color)
{
	if (map->range.color_min > color)
		map->range.color_min = color;
	if (map->range.color_max < color)
		map->range.color_max = color;
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

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			map->array[i][j].x = (int)((double)map->array[i][j].x \
									* map->scale);
			map->array[i][j].y = (int)((double)map->array[i][j].y \
									* map->scale);
			map->array[i][j].z = (int)((double)map->array[i][j].z \
									* map->scale);
			j++;
		}
		i++;
	}
}

void	pos_set(t_map *map, int width, int height)
{
	map->pos.x = (width / 2) - (map->range.x_max + map->range.x_min) / 2;
	map->pos.y = (height / 2) - (map->range.y_max + map->range.y_min) / 2;
}


void	repos_xy(t_map *map)
{
	int		i;
	int		j;
	int		z_range;
	double	z_pos;

	z_range = map->range.z_max - map->range.z_min;
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			map->array[i][j].x += map->pos.x;
			map->array[i][j].y += map->pos.y;
			z_pos = (double)(map->array[i][j].z - map->range.z_min) \
					/ (double)z_range;
			// map->array[i][j].color = (int)((1 - z_pos) * map->range.color_min + \
			// 								z_pos * map->range.color_max);
			j++;
		}
		i++;
	}
}
