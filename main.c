#include "fdf.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		put_errormessage("Invalid number of arguments\n");
	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		exit(1);
	read_map(map, av[1]);
	ft_isometric_projection(map);
	lst_print(map);
	ft_mlx(map);
	return (0);
}
