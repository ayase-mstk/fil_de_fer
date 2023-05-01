// #include <X11/keysymd.h>
#include "mlx.h"
#include "fdf.h"
#include "keymap.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	// バイトがアラインメントされていない、つまりline_lengthが実際のウィンドウ幅と異なっているので、
	//メモリオフセット(dst)は必ずmlx_get_data_addrで設定された行長を使用して計算する必要がある。
	*(unsigned int *)dst = color;
}

int	close_esc(int keycode, t_data *data)
{
	// printf("keycode : %d\n", keycode);
	// printf("XK_Escape : %d\n", KEY_ESCAPE);
	if (keycode == KEY_ESCAPE)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	put_line1(t_map *map, t_img *img, int i, int j)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = map->array[i][j].x;
	tmp_y = map->array[i][j].y;
	while (tmp_x < map->array[i][j + 1].x * 10)
	{
		while (tmp_y < map->array[i + 1][j].y * 10)
		{
			my_mlx_pixel_put(img, tmp_x, tmp_y, 0x00FFFF);
			tmp_y++;
		}
		tmp_x++;
	}
	return (0);
}

int	ft_bresenham(t_map *map, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row - 1)
	{
		j = 0;
		while (j < map->col - 1)
		{
			int	slope_right = (map->array[i][j + 1].x - map->array[i][j].x) /\
						(map->array[i][j + 1].y - map->array[i][j].y);
			if (slope_right < 1)
				put_line1(map, img, i, j);
			int	slope_down = (map->array[i + 1][j].x - map->array[i][j].x) /\
						(map->array[i + 1][j].y - map->array[i][j].y);
			if (slope_down < 1)
				put_line1(map, img, i , j);
			
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_mlx(t_map *map)
{
	t_data	data;
	t_img	img;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 1000, "mlx 42");
	mlx_clear_window(data.mlx_ptr, data.win_ptr);
	img.img = mlx_new_image(data.mlx_ptr, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
								&img.line_length, &img.endian); //メモリに保存されている画像の先頭アドレスを指すポインタを返す。このポインタから画像を修正することができる。
	ft_bresenham(map, &img);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img, 0, 0);

	mlx_key_hook(data.win_ptr, close_esc, &data);
	// mlx_mouse_hook(data.win_ptr, deal_mouse, &data);
	// mlx_mouse_move(data.win_ptr, 250, 250);
	mlx_loop(data.mlx_ptr);
	// クリックしたら終了する処理を実装する。
}

// cc -Wall -Wextra -Werror main.c -Imlx -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit