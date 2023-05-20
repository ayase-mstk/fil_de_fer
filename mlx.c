#include "fdf.h"

int	close_window(t_map *map)
{
	mlx_destroy_image(map->data->mlx_ptr, map->img->img);
	mlx_destroy_window(map->data->mlx_ptr, map->data->win_ptr);
	mlx_destroy_display(map->data->mlx_ptr);
	free_map(map);
	exit(0);
}

int	deal_key(int keycode, t_map *map)
{
	// printf("XK_Escape : %d\n", KEY_ESCAPE);
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(map->data->mlx_ptr, map->img->img);
		mlx_destroy_window(map->data->mlx_ptr, map->data->win_ptr);
		mlx_destroy_display(map->data->mlx_ptr);
		free_map(map);
		exit(0);
	}
	else if (keycode == XK_p || keycode == 112)
	{
		draw_para(map);
	}
	else if (keycode == XK_i)
	{
		draw_iso(map);
	}
	return (0);
}

void	zoom_points(t_map *map)
{
	int	i;
	int	j;

	if (map->zoom == 0)
		return ;
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			map->array[i][j].x *= map->zoom;
			map->array[i][j].y *= map->zoom;
			map->array[i][j].z *= map->zoom;
			j++;
		}
		i++;
	}
}

void	ft_zoom(int button, t_map *map)
{
	mlx_destroy_image(map->data->mlx_ptr, map->img->img);
	if (button == 4)
		map->zoom -= 1;
	else if (button == 5)
		map->zoom += 1;
	zoom_points(map);
	ft_isometric_projection(map);
	map_range(map, map->iso);
	pos_set(map);
	repos_xy(map, map->iso);
	draw_image(map, map->iso);
}

int	deal_mouse(int button, int x, int y, t_map *map)
{
	x *= y;
	y *= x;
	if (button == 4 || button == 5)
		ft_zoom(button, map);
	return (0);
}

int	expose_hook(t_map *map)
{
	mlx_put_image_to_window(map->data->mlx_ptr, map->data->win_ptr, \
							map->img->img, 0, 0);
	return (0);
}

void	set_hooks(t_map *map)
{
	mlx_hook(map->data->win_ptr, 17, 1L<<17, close_window, map);
	mlx_key_hook(map->data->win_ptr, deal_key, map);
	mlx_mouse_hook(map->data->win_ptr, deal_mouse, map);
	mlx_expose_hook(map->data->win_ptr, expose_hook, map);
}

// void	ft_mlx(t_map *map)
// {
// 	draw_iso(map);
// 	lst_print(map, map->array);
// 	// set_hook(map);
// 	mlx_hook(map->data->win_ptr, 17, 1L<<17, close_window, map);
// 	mlx_key_hook(map->data->win_ptr, deal_key, map);
// 	mlx_mouse_hook(map->data->win_ptr, deal_mouse, map->data);
// 	mlx_expose_hook(map->data->win_ptr, expose_hook, map);
// 	mlx_loop(map->data->mlx_ptr);
// 	// クリックしたら終了する処理を実装する。
// }

// cc -Wall -Wextra -Werror main.c -Imlx -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit