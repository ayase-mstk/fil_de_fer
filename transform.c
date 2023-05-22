/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:09:29 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/22 15:09:30 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric_projection(t_map *map)
{
	int		i;
	int		j;
	int		tmp_x;
	int		tmp_y;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			tmp_x = map->array[i][j].x;
			tmp_y = map->array[i][j].y;
			map->iso[i][j].x = (tmp_y - tmp_x) * cos(30 * M_PI / 180.0);
			map->iso[i][j].y = -map->array[i][j].z + (tmp_x + tmp_y) \
									* sin(30 * M_PI / 180.0);
			j++;
		}
		i++;
	}
}

void	ft_rotation_x(t_map *map, t_mappoint **array, double theeta)
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
			tmp_y = array[i][j].y;
			tmp_z = array[i][j].z;
			array[i][j].y = tmp_y * cos(theeta * M_PI / 180.0) \
									+ tmp_z * sin(theeta * M_PI / 180.0);
			array[i][j].z = -tmp_y * sin(theeta * M_PI / 180.0) \
									+ tmp_z * cos(theeta * M_PI / 180.0);
			j++;
		}
		i++;
	}
}

void	ft_rotation_y(t_map *map, t_mappoint **array, double theeta)
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
			tmp_x = array[i][j].x;
			tmp_z = array[i][j].z;
			array[i][j].x = tmp_x * cos(theeta * M_PI / 180.0) \
									+ tmp_z * sin(theeta * M_PI / 180.0);
			array[i][j].z = -tmp_x * sin(theeta * M_PI / 180.0) \
									+ tmp_z * cos(theeta * M_PI / 180.0);
			j++;
		}
		i++;
	}
}

void	ft_rotation_z(t_map *map, t_mappoint **array, double theeta)
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
			tmp_x = array[i][j].x;
			tmp_y = array[i][j].y;
			array[i][j].x = tmp_x * cos(theeta * M_PI / 180.0) \
										- tmp_y * sin(theeta * M_PI / 180.0);
			array[i][j].y = tmp_x * sin(theeta * M_PI / 180.0) \
										+ tmp_y * cos(theeta * M_PI / 180.0);
			j++;
		}
		i++;
	}
}

void	ft_rotation(t_map *map, t_mappoint **array)
{
	ft_rotation_x(map, array, map->theeta_x);
	ft_rotation_y(map, array, map->theeta_y);
	ft_rotation_z(map, array, map->theeta_z);
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
