#include "fdf.h"

static void	init_iso(t_map *map)
{
	int			i;
	int			j;

	map->iso = (t_mappoint **)malloc(sizeof(t_mappoint *) * map->row);
	if (map->iso == NULL)
		exit(1);
	i = 0;
	while (i < map->row)
	{
		map->iso[i] = (t_mappoint *)malloc(sizeof(t_mappoint) * map->col);
		if (map->iso[i] == NULL)
			exit(1);
		j = 0;
		while (j < map->col)
		{
			map->iso[i][j].x = 0;
			map->iso[i][j].y = 0;
			map->iso[i][j].z = map->array[i][j].z;
			map->iso[i][j].color = map->array[i][j].color;
			j++;
		}
		i++;
	}
}

void	draw_iso(t_map *map)
{
	if (map->iso == NULL)
	{
		init_iso(map);
	}
	ft_isometric_projection(map);
	lst_print(map, map->iso); //
	repos_xy(map, map->iso);
	draw_image(map, map->iso);
	mlx_put_image_to_window(map->data->mlx_ptr, map->data->win_ptr, \
							map->img->img, 0, 0);
}

static void	malloc_para(t_map *map)
{
	int			i;

	map->para = (t_mappoint **)malloc(sizeof(t_mappoint *) * map->row);
	if (map->para == NULL)
		exit(1);
	i = 0;
	while (i < map->row)
	{
		map->para[i] = (t_mappoint *)malloc(sizeof(t_mappoint) * map->col);
		if (map->para[i] == NULL)
			exit(1);
		i++;
	}
}

static void	init_para(t_map *map)
{
	int			i;
	int			j;
	
	if (map->para == NULL)
		malloc_para(map);
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			map->para[i][j].x = map->array[i][j].x;
			map->para[i][j].y = map->array[i][j].y;
			map->para[i][j].z = map->array[i][j].z;
			map->para[i][j].color = map->array[i][j].color;
			j++;
		}
		i++;
	}
}

void	draw_para(t_map *map)
{
	// mlx_destroy_image(map->data->mlx_ptr, map->img->img);
	// // mlx_clear_window(map->data->mlx_ptr, map->data->win_ptr);
	// map->img->img = mlx_new_image(map->data->mlx_ptr, WIDTH, HEIGHT);
	// map->img->addr = mlx_get_data_addr(map->img->img, \
	// 									&map->img->bits_per_pixel, \
	// 									&map->img->line_length, \
	// 									&map->img->endian);
	ft_bzero(map->img->addr, WIDTH * HEIGHT * (map->img->bits_per_pixel / 8));
	init_para(map);
	repos_xy(map, map->para);
	lst_print(map, map->para);
	draw_image(map, map->para);
}
