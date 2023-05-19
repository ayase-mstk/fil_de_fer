#include "fdf.h"

int	zoom(int key, t_map *map)
{
	if (key == 69)
		map->scale += 0.1;
	else if (key == 78)
		map->scale -= 0.1;
	if (map->scale < 0.1)
		map->scale = 0.1;
	return (0);
}
