#include "fdf.h"

void	ft_rotation_z(t_map *map, double theeta)
{
	int		i;
	int		j;
	double	sum;
	double	rotation_z[3][3];

	i = 0;
	rotation_z[0][0] = cos(theeta * M_PI / 180.0);
	rotation_z[0][1] = -sin(theeta * M_PI / 180.0);
	rotation_z[0][2] = 0;
	rotation_z[1][0] = sin(theeta * M_PI / 180.0);
	rotation_z[1][1] = cos(theeta * M_PI / 180.0);
	rotation_z[1][2] = 0;
	rotation_z[2][0] = 0;
	rotation_z[2][1] = 0;
	rotation_z[2][2] = 1;
	while (i < map->row)
	{
		j = 0;
		sum = 0.0;
		while (j < map->col)
		{
			sum += map->array[i][j].x * rotation_z[i][j];
			sum += map->array[i][j].y * rotation_z[i][j];
			j++;
		}
		if (i == 0)
			map->array[i][j].x = sum;
		else if (i == 1)
			map->array[i][j].y = sum;
		else
			map->array[i][j].z = sum;
		i++;
	}
}

// rotation matrix

// Rx(θ) = [1  0      0   ]
//         [0  cosθ  -sinθ]
//         [0  sinθ   cosθ]

// Ry(θ) = [cosθ   0  sinθ]
//         [0      1  0   ]
//         [-sinθ  0  cosθ]

// Rz(θ) = [cosθ  -sinθ  0]
//         [sinθ   cosθ  0]
//         [0      0     1]

// ex)
// P = [1]
//	   [2]
//	   [4]
// Rz(θ) * [x] = [x'] = [cosθ  -sinθ  0] * [1] 
//         [y]   [y']   [sinθ   cosθ  0]   [2]   
//         [z]   [z']   [0      0     1]   [4]   

// = [cosθ * 1 - sinθ * 2 + 0 * 4] = [cosθ - 2sinθ]
//	 [sinθ * 1 + cosθ * 2 + 0 * 4]   [sinθ + 2cosθ
//	 [4 					     ]   [4]
