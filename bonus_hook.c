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
