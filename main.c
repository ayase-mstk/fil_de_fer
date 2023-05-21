#include "fdf.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		put_errormessage("Invalid number of arguments\n");
	map = init_map();
	read_map(map, av[1]);
	scale_points(map);
	init_mlx(map);
	draw_iso(map);
	set_hooks(map);
	mlx_loop(map->data->mlx_ptr);
	return (0);
}
