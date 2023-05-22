/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:59:04 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/22 15:59:11 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		exit (0);
	}
	map = init_map();
	read_map(map, av[1]);
	scale_points(map);
	init_mlx(map);
	draw_iso(map);
	set_hooks(map);
	mlx_loop(map->data->mlx_ptr);
	return (0);
}
