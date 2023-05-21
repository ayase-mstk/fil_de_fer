#include "fdf.h"

int	close_window(t_map *map)
{
	mlx_destroy_image(map->data->mlx_ptr, map->img->img);
	mlx_destroy_window(map->data->mlx_ptr, map->data->win_ptr);
	mlx_destroy_display(map->data->mlx_ptr);
	free(map->data);
	free(map->img);
	free_map(map, map->row);
	exit(0);
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

int	deal_key(int keycode, t_map *map)
{
	// printf("XK_Escape : %d\n", KEY_ESCAPE);
	// printf("keycode : %x\n", keycode);
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(map->data->mlx_ptr, map->img->img);
		mlx_destroy_window(map->data->mlx_ptr, map->data->win_ptr);
		mlx_destroy_display(map->data->mlx_ptr);
		free(map->data);
		free(map->img);
		free_map(map, map->row);
		exit(0);
	}
	else if (keycode == XK_p || keycode == 112)
		draw_para(map);
	else if (keycode == XK_i)
		draw_iso(map);
	else if (keycode == XK_g)
		map->color_mode = GRADATION;
	else if (keycode == XK_n)
		map->color_mode = NORMAL;
	else if (keycode == XK_Left || keycode == XK_Up \
			|| keycode == XK_Right || keycode == XK_Down)
		ft_move(keycode, map);
	else if (keycode == XK_x || keycode == XK_y || keycode == XK_z)
		set_axis(keycode, map);
	// else if (keycode == XK_comma || keycode == XK_period)
	// 	ft_rotate(keycode, map);
	return (0);
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
