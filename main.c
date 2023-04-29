#include "fdf.h"
#include "mlx.h"
#include <X11/keysym.h>

int	input_data(t_map *map, char *map_data)
{
	size_t		i;
	size_t		j;
	int			fd;
	char		*line;

	i = 0;
	fd = open(map_data, O_RDONLY);
	while (1)
	{
		j = 0;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (line[j] == '\n' || line[j] == "\0")
		{
			lst_pushback(map, i, j, line[j]);
			j++;
		}
		map->col = j;
		free(line);
		i++;
	}
	map->row = i;
	return (0);
}

int	main(int ac, char **av)
{
	t_map	*map;

	map = map_init(map);
	input_data(map, av[1]);
	return (0);
}
