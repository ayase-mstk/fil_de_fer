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
	map->data->win_ptr = mlx_new_window(map->data->mlx_ptr, WIDTH, HEIGHT, "mlx 42");
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
	map->zoom = 0;
	map->row = 0;
	map->col = 0;
	map->array = NULL;
	map->para = NULL;
	map->iso = NULL;
	return (map);
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		put_errormessage("Invalid number of arguments\n");
	map = init_map();
	read_map(map, av[1]);
	scale_points(map);
	// parallel ok
	init_mlx(map);
	draw_iso(map);
	set_hooks(map);
	mlx_loop(map->data->mlx_ptr);
	return (0);
}
