#include "fdf.h"

void	map_range(t_map *map, double x, double y)
{
	if (map->xy.x_min > x)
		map->xy.x_min = x;
	if (map->xy.x_max < x)
		map->xy.x_max = x;
	if (map->xy.y_min > y)
		map->xy.y_min = y;
	if (map->xy.y_max < y)
		map->xy.y_max = y;
}

void	pos_set(t_map *map, int width, int height)
{
	map->pos.x = (width / 2) - (map->xy.x_max + map->xy.x_min) / 2;
	map->pos.y = (height / 2) - (map->xy.y_max + map->xy.y_min) / 2;
}

void	repos_xy(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			map->array[i][j].x += map->pos.x;
			map->array[i][j].y += map->pos.y;
			j++;
		}
		i++;
	}
}
