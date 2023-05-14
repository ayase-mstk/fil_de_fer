#include "fdf.h"

void	ft_isometric1(t_map *map)
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
			map->array[i][j].y = tmp_y * cos(0.523599) - tmp_z * sin(0.523599);
			map->array[i][j].z = tmp_y * sin(0.523599) + tmp_z * cos(0.523599); 
			j++;
		}
		i++;
	}
}

void	ft_isometric2(t_map	*map)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_y;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			tmp_x = map->array[i][j].x;
			tmp_y = map->array[i][j].z;
			map->array[i][j].x = tmp_x * cos(0.523599) + tmp_y * sin(0.523599);
			map->array[i][j].y = -tmp_x * sin(0.523599) + tmp_y * cos(0.523599);
			j++;
		}
		i++;
	}
}

void	ft_isometric_projection(t_map *map)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_y;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			tmp_x = map->array[i][j].x;
			tmp_y = map->array[i][j].y;
			map->array[i][j].x = (tmp_y - tmp_x) * cos(30 * M_PI / 180.0);
			map->array[i][j].y = -map->array[i][j].z + (tmp_x + tmp_y) \
									* sin(30 * M_PI / 180.0);
			j++;
		}
		i++;
	}
}

void	ft_rotation_x(t_map *map, double theeta)
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
			map->array[i][j].y = tmp_y * cos(theeta * M_PI / 180.0) \
									+ tmp_z * sin(theeta * M_PI / 180.0);
			map->array[i][j].z = -tmp_y * sin(theeta * M_PI / 180.0) \
									+ tmp_z * cos(theeta * M_PI / 180.0);
			j++;
		}
		i++;
	}
}

void	ft_rotation_y(t_map *map, double theeta)
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
			map->array[i][j].x = tmp_x * cos(theeta * M_PI / 180.0) \
									+ tmp_z * sin(theeta * M_PI / 180.0);
			map->array[i][j].z = -tmp_x * sin(theeta * M_PI / 180.0) \
									+ tmp_z * cos(theeta * M_PI / 180.0);
			j++;
		}
		i++;
	}
}

void	ft_rotation_z(t_map *map, double theeta)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_y;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			tmp_x = map->array[i][j].x;
			tmp_y = map->array[i][j].y;
			map->array[i][j].x = tmp_x * cos(theeta * M_PI / 180.0) \
										- tmp_y * sin(theeta * M_PI / 180.0);
			map->array[i][j].y = tmp_x * sin(theeta * M_PI / 180.0) \
										+ tmp_y * cos(theeta * M_PI / 180.0);
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