#include "fdf.h"

void	init_map(t_map *map)
{
	map->data = (t_data *)malloc(sizeof(t_data));
	if (map->data == NULL)
		exit(1);
	map->img = (t_img *)malloc(sizeof(t_img));
	if (map->img == NULL)
		exit(1);
	map->range.x_max = INT_MIN;
	map->range.y_max = INT_MIN;
	map->range.z_max = INT_MIN;
	map->range.color_max = INT_MIN;
	map->range.x_min = INT_MAX;
	map->range.y_min = INT_MAX;
	map->range.z_min = INT_MAX;
	map->range.color_min = INT_MAX;
	map->scale = 0;
	map->zoom = 0;
	map->row = 0;
	map->col = 0;
	map->array = NULL;
	map->data->mlx_ptr = NULL;
	map->data->win_ptr = NULL;
	map->img->img = NULL;
	map->img->addr = NULL;
	map->img->bits_per_pixel = 0;
	map->img->line_length = 0;
	map->img->endian = 0;
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		put_errormessage("Invalid number of arguments\n");
	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		exit(1);
	init_map(map);
	read_map(map, av[1]);
	ft_isometric_projection(map);
	ft_mlx(map);
	return (0);
}
