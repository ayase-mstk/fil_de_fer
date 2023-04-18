#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// バイトがアラインメントされていない、つまりline_lengthが実際のウィンドウ幅と異なっているので、
	//メモリオフセット(dst)は必ずmlx_get_data_addrで設定された行長を使用して計算する必要がある。
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	// if (!mlx)
	// {
	// 	printf("mlx_init error(%d)\n", errno);
	// 	return (-1);
	// }
	mlx_win = mlx_new_window(mlx, 1920, 1080, "mlx 42");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
								&img.line_length, &img.endian); //画像のアドレスゲット
	printf("bits_per_pixel : %d\nline_length : %d\nendian : %d\n", \
			img.bits_per_pixel, img.line_length, img.endian);
	my_mlx_pixel_put(&img, 100, 100, 0x0000FFFF); //
	mlx_put_image_to_window(mlx, mlx_win, img.img, 960, 540);
	mlx_loop(mlx);
}

// cc -Wall -Wextra -Werror main.c -Imlx -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit