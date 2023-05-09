#include "fdf.h"

// void	ft_rotation_z(t_map *map)
// {
// 	int		i;
// 	int		j;
// 	double	sum;
// 	double	rotation_z[3][3];

// 	i = 0;
// 	rotation_z[0][0] = cos(M_PI / 4.0);
// 	rotation_z[0][1] = -sin(M_PI / 4.0);
// 	rotation_z[0][2] = 0;
// 	rotation_z[1][0] = sin(M_PI / 4.0);
// 	rotation_z[1][1] = cos(M_PI / 4.0);
// 	rotation_z[1][2] = 0;
// 	rotation_z[2][0] = 0;
// 	rotation_z[2][1] = 0;
// 	rotation_z[2][2] = 1;
// 	while (i < map->row - 1)
// 	{
// 		j = 0;
// 		sum = 0.0;
// 		while (j < map->col - 1)
// 		{
// 			sum += map->array[i][j].x * rotation_z[i][j];
// 			sum += map->array[i][j].y * rotation_z[i][j];
// 			j++;
// 		}
// 		if (i == 0)
// 			map->array[i][j].x = sum;
// 		else if (i == 1)
// 			map->array[i][j].y = sum;
// 		else
// 			map->array[i][j].z = sum;
// 		i++;
// 	}
// }

void	ft_rotation_x(t_map *map)
{
	int		i;
	int		j;
	double	tmp_y;
	double	tmp_z;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			tmp_y = map->array[i][j].y;
			tmp_z = map->array[i][j].z;
			map->rotate_array[i][j].y = tmp_y * cos(M_PI / 4) - tmp_z * sin(M_PI / 4);
			map->rotate_array[i][j].z = tmp_y * sin(M_PI / 4) + tmp_z * cos(M_PI / 4);
			j++;
		}
		i++;
	}
}

void	ft_rotation_y(t_map *map)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_z;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			tmp_x = map->array[i][j].x;
			tmp_z = map->array[i][j].z;
			map->rotate_array[i][j].x = tmp_x * cos(M_PI / 4) + tmp_z * sin(M_PI / 4);
			map->rotate_array[i][j].z = -tmp_x * sin(M_PI / 4) + tmp_z * cos(M_PI / 4);
			j++;
		}
		i++;
	}
}

void	ft_rotation_z(t_map *map)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_y;

	j = 0;
	while (j < map->row)
	{
		i = 0;
		while (i < map->col)
		{
			tmp_x = map->array[i][j].x;
			tmp_y = map->array[i][j].y;
			map->rotate_array[i][j].x = tmp_x * cos(M_PI / 4) \
										- tmp_y * sin(M_PI / 4) \
										+ (map->row - 1) / 2;
			map->rotate_array[i][j].y = tmp_x * sin(M_PI / 4) \
										+ tmp_y * cos(M_PI / 4) \
										+ (map->col - 1) / 2;
			j++;
		}
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