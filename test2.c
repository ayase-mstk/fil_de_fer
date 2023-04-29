#include <X11/keysym.h>
#include "mlx.h"
#include "fdf.h"
// #include "keymap.h"

int	deal_key(int keycode, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	printf("keycode : %d\n", keycode);
	printf("XK_Escape : %d\n", XK_Escape);
	if (keycode == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	else
	{
		while (i < 100)
		{
			j = 0;
			while (j < 100)
			{
				if (i == 0 || j == 0 || i == 99 || j == 99)
					mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0x00FFFF);
				j++;
			}
			i++;
		}
	}
	return (0);
}

int	deal_mouse(int button, int x, int y, t_data *data)
{
	// if (button == 1)
	// {
	// 	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x00FFFF);
	// }
	// printf("button : %d\nx : %d\ny : %d\n", button, x, y);
	return (0);
}

int	main(void)
{
	t_data	data;
	// t_img	img;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "mlx 42");
	// mlx_clear_window(data.mlx_ptr, data.win_ptr);
	// img.img = mlx_new_image(data.mlx_ptr, 250, 250);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	// 							&img.line_length, &img.endian); //メモリに保存されている画像の先頭アドレスを指すポインタを返す。このポインタから画像を修正することができる。
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img, 0, 0);
	// mlx_pixel_put(data.mlx_ptr, data.win_ptr, 0, 0, 0xFFFFFF);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	// mlx_mouse_hook(data.win_ptr, deal_mouse, &data);
	// mlx_mouse_move(data.win_ptr, 250, 250);
	mlx_loop(data.mlx_ptr);
	// クリックしたら終了する処理を実装する。
}

// void	render_next_frame(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < 100)
// 	{
// 		j = 0;
// 		while (j < 100)
// 		{
// 			if (i == 0 || j == 0 || i == 99 || j == 99)
// 				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0x00FFFF);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	t_data	data;
// 	t_img	img;

// 	data.mlx_ptr = mlx_init();
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "mlx 42");
// 	mlx_loop_hook(data.mlx_ptr, render_next_frame, &data);
// 	mlx_loop(data.mlx_ptr);
// 	// クリックしたら終了する処理を実装する。
// }