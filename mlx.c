#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// バイトがアラインメントされていない、つまりline_lengthが実際のウィンドウ幅と異なっているので、
	//メモリオフセット(dst)は必ずmlx_get_data_addrで設定された行長を使用して計算する必要がある。
	*(unsigned int *)dst = color;
}

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	win_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_data	data;
	// t_data	img;
	// t_data	img_tmp;

	data.mlx_ptr = mlx_init();
	// if (data.mlx_ptr == NULL)
	// {
	// 	printf("mlx_init error(%d)\n", errno);
	// 	return (MLX_INIT_ERROR);
	// }
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "mlx 42");
	// if (data.win_ptr == NULL)
	// {
	// 	printf("mlx_new_window error(%d)\n", errno);
	// 	return (MLX_NEW_WINDOW_ERROR);
	// }
	// img.img = mlx_new_image(vars.mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	// 							&img.line_length, &img.endian); //画像のアドレスゲット
	// printf("bits_per_pixel : %d\nline_length : %d\nendian : %d\n", \
	// 		img.bits_per_pixel, img.line_length, img.endian);
	// my_mlx_pixel_put(&img, 50, 50, 0x0000FFFF);
	// img_tmp = img;
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 960, 540);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	mlx_loop(data.mlx_ptr);
	// mlx_destroy_image(vars.mlx, img.img);
	// mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}

// cc -Wall -Wextra -Werror main.c -Imlx -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit