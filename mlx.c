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
	// printf("keycode : %d\n", keycode);
	// printf("XK_Escape : %d\n", KEY_ESCAPE);
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(map->data->mlx_ptr, map->img->img);
		mlx_destroy_window(map->data->mlx_ptr, map->data->win_ptr);
		mlx_destroy_display(map->data->mlx_ptr);
		free_map(map);
		exit(0);
	}
	return (0);
}

void	ft_zoom(int button, t_map *map)
{
	mlx_destroy_image(map->data->mlx_ptr, map->img->img);
	printf("map->zoom : %d\n", map->zoom);
	if (button == 4)
		map->zoom -= 1;
	else if (button == 5)
		map->zoom += 1;
	printf("map->zoom : %d\n", map->zoom);
	re_draw_image(map);
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

void	set_hook(t_map *map)
{
	mlx_hook(map->data->win_ptr, 17, 1L<<17, close_window, map);
	mlx_key_hook(map->data->win_ptr, deal_key, map);
	mlx_mouse_hook(map->data->win_ptr, deal_mouse, map);
	mlx_expose_hook(map->data->win_ptr, expose_hook, map);
	// mlx_mouse_move(map->data->win_ptr, 250, 250);
}

void	ft_mlx(t_map *map)
{
	map->data = malloc(sizeof(t_data));
	map->img = malloc(sizeof(t_img));
	map->data->mlx_ptr = mlx_init();
	map->data->win_ptr = mlx_new_window(map->data->mlx_ptr, WIDTH, HEIGHT, "mlx 42");
	mlx_clear_window(map->data->mlx_ptr, map->data->win_ptr);
	map->img->img = mlx_new_image(map->data->mlx_ptr, WIDTH, HEIGHT);
	map->img->addr = mlx_get_data_addr(map->img->img, \
										&map->img->bits_per_pixel, \
										&map->img->line_length, \
										&map->img->endian);
	draw_image(map);
	mlx_put_image_to_window(map->data->mlx_ptr, \
		map->data->win_ptr, map->img->img, 0, 0);

	// set_hook(map);
	mlx_hook(map->data->win_ptr, 17, 1L<<17, close_window, map);
	mlx_key_hook(map->data->win_ptr, deal_key, map);
	mlx_mouse_hook(map->data->win_ptr, deal_mouse, map->data);
	mlx_expose_hook(map->data->win_ptr, expose_hook, map);
	mlx_loop(map->data->mlx_ptr);
	// クリックしたら終了する処理を実装する。
}

// cc -Wall -Wextra -Werror main.c -Imlx -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit