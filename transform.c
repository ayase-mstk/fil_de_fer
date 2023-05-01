#include "fdf.h"

void	ft_rotation_z(t_map *map)
{
	int		i;
	int		j;
	double	x;
	double	y;
	double	z;
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			x = map->array[i][j].x;
			y = map->array[i][j].y;
			z = map->array[i][j].z;
			map->array[i][j].x = x * cos(45.0 * M_PI / 180.0) + y * cos(45.0 * M_PI / 180.0);
			map->array[i][j].y = -x * sin(45.0 * M_PI / 180.0) + y * sin(45.0 * M_PI / 180.0) - z;
			map->array[i][j].z = x * sin(45.0 * M_PI / 180.0) + y * sin(45.0 * M_PI / 180.0) + z;
			j++;
		}
		i++;
	}
}

// R(θ) = [cosθ  -sinθ  0]
//        [sinθ   cosθ  0]
//        [0      0     1]

//[x] = [1]
//		[0]
//		[4]
// R(θ) * [x] = [x'] = [cosθ  -sinθ  0] * [1] = [cosθ]
//        [y]   [y']   [sinθ   cosθ  0]   [0]   [sinθ]
//        [z]   [z']   [0      0     1]   [4]   [4]