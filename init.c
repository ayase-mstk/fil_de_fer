#include "fdf.h"

void	init_mlx(t_map *map)
{
	map->data = (t_data *)malloc(sizeof(t_data));
	if (map->data == NULL)
		exit(1);
	map->img = (t_img *)malloc(sizeof(t_img));
	if (map->img == NULL)
		exit(1);
	map->data->mlx_ptr = mlx_init();
	map->data->win_ptr = mlx_new_window(map->data->mlx_ptr, \
										WIDTH, HEIGHT, "mlx 42");
	map->img->img = mlx_new_image(map->data->mlx_ptr, WIDTH, HEIGHT);
	map->img->addr = mlx_get_data_addr(map->img->img, \
										&map->img->bits_per_pixel, \
										&map->img->line_length, \
										&map->img->endian);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		exit(1);
	map->data = NULL;
	map->img = NULL;
	map->zoom = 1.0;
	map->move_x = 0;
	map->move_y = 0;
	map->row = 0;
	map->col = 0;
	map->array = NULL;
	map->para = NULL;
	map->iso = NULL;
	map->color_mode = NORMAL;
	return (map);
}

void	init_range(t_range *range)
{
	range->x_max = INT_MIN;
	range->y_max = INT_MIN;
	range->z_max = INT_MIN;
	range->color_max = INT_MIN;
	range->x_min = INT_MAX;
	range->y_min = INT_MAX;
	range->z_min = INT_MAX;
	range->color_min = INT_MAX;
}

void	malloc_iso(t_map *map)
{
	int			i;

	map->iso = (t_mappoint **)malloc(sizeof(t_mappoint *) * map->row);
	if (map->iso == NULL)
		exit(1);
	i = 0;
	while (i < map->row)
	{
		map->iso[i] = (t_mappoint *)malloc(sizeof(t_mappoint) * map->col);
		if (map->iso[i] == NULL)
			exit(1);
		i++;
	}
}

void	init_iso(t_map *map)
{
	int			i;
	int			j;

	if (map->iso == NULL)
		malloc_iso(map);
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			map->iso[i][j].x = 0;
			map->iso[i][j].y = 0;
			map->iso[i][j].z = map->array[i][j].z;
			map->iso[i][j].color = map->array[i][j].color;
			j++;
		}
		i++;
	}
}
