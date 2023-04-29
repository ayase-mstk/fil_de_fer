#include "fdf.h"
#include "mlx.h"
#include <X11/keysym.h>

t_mappoint	*new_point(double x, double y, double z)
{
	t_mappoint	*point;

	point = (t_mappoint *)malloc(sizeof(t_mappoint));
	if (point == NULL)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->next = NULL;
	return (point);
}

int	input_data(t_mappoint *head, char *map_data)
{
	size_t		i;
	size_t		j;
	int			fd;
	char		*line;
	t_mappoint	*point;

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
			point = new_point(i, j, line[j]);
			j++;
		}
		free(line);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	t_map	*map;

	map = map_init(map);
	input_data(map->head, av[1]);
	return (0);
}
