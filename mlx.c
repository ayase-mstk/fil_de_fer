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
	// printf("keycode : %d\n", keycode);s
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

// int	deal_mouse(int button, int x, int y, t_data *data)
// {
// 	printf("button : %d\n", button);
// 	printf("x : %d\n", x);
// 	printf("y : %d\n", y);
// 	return (0);
// }

int	expose_hook(t_map *map)
{
	mlx_put_image_to_window(map->data->mlx_ptr, map->data->win_ptr, \
							map->img->img, 0, 0);
	return (0);
}

void	ft_mlx(t_map *map)
{
	t_data	data;
	t_img	img;

	map->data = &data;
	map->img = &img;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "mlx 42");
	mlx_clear_window(data.mlx_ptr, data.win_ptr);
	img.img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
								&img.line_length, &img.endian);
	draw_line(map, &img);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img, 0, 0);

	mlx_hook(data.win_ptr, 17, 1L<<17, close_window, map);
	mlx_key_hook(data.win_ptr, deal_key, map);
	// mlx_mouse_hook(data.win_ptr, deal_mouse, &data);
	mlx_expose_hook(data.win_ptr, expose_hook, map);
	// mlx_mouse_move(data.win_ptr, 250, 250);
	mlx_loop(data.mlx_ptr);
	// クリックしたら終了する処理を実装する。
}

// cc -Wall -Wextra -Werror main.c -Imlx -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit