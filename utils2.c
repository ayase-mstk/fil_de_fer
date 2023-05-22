/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masa <masa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:02:46 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/22 19:02:31 by masa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	maparray_and_strarr_free(t_map *map, char **strarr, int size)
{
	free_map(map, size);
	free_strarr(strarr);
	exit(1);
}

void	set_axis(int keycode, t_map *map)
{
	if (keycode == XK_x)
		map->axis = X;
	else if (keycode == XK_y)
		map->axis = Y;
	else if (keycode == XK_z)
		map->axis = Z;
}

static	unsigned int	ft_check_num(char c, char *base1, char *base2)
{
	int	i;

	i = 0;
	while (base1[i])
	{
		if (c == base1[i] || c == base2[i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base1, char *base2)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result *= 16;
		result += 0x0 + ft_check_num(str[i], base1, base2);
		i++;
	}
	return (result);
}

void	lst_print(t_map *map, t_mappoint **array)
{
	int			i;
	int			j;
	t_mappoint	now;

	i = 0;
	while (i < map->row && array[i])
	{
		j = 0;
		while (j < map->col)
		{
			now = array[i][j];
			ft_printf("x=%d, y=%d, z=%d, color=%x\n", \
						now.x, now.y, now.z, now.color);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
