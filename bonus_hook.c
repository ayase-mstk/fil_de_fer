#include "fdf.h"

void	zoom_points(t_map *map, t_mappoint **array)
{
	int	i;
	int	j;

	if (map->zoom <= 0)
		return ;
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			array[i][j].x *= map->zoom;
			array[i][j].y *= map->zoom;
			array[i][j].z *= map->zoom;
			j++;
		}
		i++;
	}
}

void	move_points(t_map *map, t_mappoint **array)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			array[i][j].x += map->move_x;
			array[i][j].y += map->move_y;
			j++;
		}
		i++;
	}
}

void	ft_zoom(int button, t_map *map)
{
	if (button == 4)
		map->zoom *= 0.95;
	else if (button == 5)
		map->zoom *= 1.05;
	ft_bzero(map->img->addr, WIDTH * HEIGHT * (map->img->bits_per_pixel / 8));
	init_iso(map);
	ft_isometric_projection(map);
	zoom_points(map, map->iso);
	repos_xy(map, map->iso);
	move_points(map, map->iso);
	draw_image(map, map->iso);
	mlx_put_image_to_window(map->data->mlx_ptr, map->data->win_ptr, \
							map->img->img, 0, 0);
}

void	ft_move(int keycode, t_map *map)
{
	if (keycode == XK_Left)
		map->move_x -= 10;
	else if (keycode == XK_Right)
		map->move_x += 10;
	else if (keycode == XK_Up)
		map->move_y -= 10;
	else if (keycode == XK_Down)
		map->move_y += 10;
	ft_bzero(map->img->addr, WIDTH * HEIGHT * (map->img->bits_per_pixel / 8));
	init_iso(map);
	ft_isometric_projection(map);
	zoom_points(map, map->iso);
	repos_xy(map, map->iso);
	move_points(map, map->iso);
	draw_image(map, map->iso);
	mlx_put_image_to_window(map->data->mlx_ptr, map->data->win_ptr, \
							map->img->img, 0, 0);
}

void	ft_rotation(t_map *map, t_mappoint **array)
{
	if (map->axis == X)
		ft_rotation_x(map, array, map->theeta_x);
	else if (map->axis == Y)
		ft_rotation_y(map, array, map->theeta_y);
	else if (map->axis == Z)
		ft_rotation_z(map, array, map->theeta_z);
}

void	ft_rotate(int keycode, t_map *map)
{
	if (keycode == XK_comma)
	{
		if (map->axis == X)
			map->theeta_x -= 0.1;
		else if (map->axis == Y)
			map->theeta_y -= 0.1;
		else if (map->axis == Z)
			map->theeta_z -= 0.1;
	}
	else if (keycode == XK_period)
	{
		if (map->axis == X)
			map->theeta_x += 0.1;
		else if (map->axis == Y)
			map->theeta_y += 0.1;
		else if (map->axis == Z)
			map->theeta_z += 0.1;
	}
	ft_bzero(map->img->addr, WIDTH * HEIGHT * (map->img->bits_per_pixel / 8));
	init_iso(map);
	ft_isometric_projection(map);
	ft_rotation(map, map->iso);
	zoom_points(map, map->iso);
	repos_xy(map, map->iso);
	move_points(map, map->iso);
	draw_image(map, map->iso);
	mlx_put_image_to_window(map->data->mlx_ptr, map->data->win_ptr, \
							map->img->img, 0, 0);
}
