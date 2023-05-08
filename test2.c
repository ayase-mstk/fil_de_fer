// #include <X11/keysymd.h>
#include "mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 1500
#define HEIGHT 1500

typedef struct	s_image
{
    void	*img_ptr;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}				t_image;

// #include "fdf.h"
// #include "keymap.h"

// void	close_esc(int keycode, t_data *data)
// {
// 	// printf("keycode : %d\n", keycode);
// 	// printf("XK_Escape : %d\n", KEY_ESCAPE);
// 	if (keycode == KEY_ESCAPE)
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// }

// void	draw_square(t_data *data)
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

// int main()
// {
//     void *mlx_ptr = mlx_init(); // mlxの初期化
//     void *win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Circle"); // ウィンドウの作成

//     int x = 250;
//     int y = 250;
//     int radius = 50;
//     int color = 0xFF0000; // 赤

//     mlx_pixel_put(mlx_ptr, win_ptr, x, y, color); // 中心の点を描画

//     // 円を描画
//     for (int i = 0; i <= radius; i++)
//     {
//         int j = (int)(sqrt(radius * radius - i * i) + 0.5);
//         mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, color); // 第1象限
//         mlx_pixel_put(mlx_ptr, win_ptr, x + i, y - j, color); // 第4象限
//         mlx_pixel_put(mlx_ptr, win_ptr, x - i, y + j, color); // 第2象限
//         mlx_pixel_put(mlx_ptr, win_ptr, x - i, y - j, color); // 第3象限
//     }

//     mlx_loop(mlx_ptr); // イベントループ開始

//     return 0;
// }

// 線を描画する関数
void draw_line(int x0, int y0, int x1, int y1, int color, t_image *img)
{
	char	*dst;

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (x0 != x1 || y0 != y1)
    {
        dst = img->addr + (y0 * img->line_length + x0 * (img->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

int main(int argc, char **argv)
{
	t_image	img;

    if (argc < 5)
    {
        printf("Usage: %s x0 y0 x1 y1\n", argv[0]);
        return 1;
    }
    int x0 = atoi(argv[1]);
    int y0 = atoi(argv[2]);
    int x1 = atoi(argv[3]);
    int y1 = atoi(argv[4]);

    void *mlx_ptr = mlx_init(); // mlxの初期化
    void *win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Line"); // ウィンドウの作成
    img.img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT); // 画像の作成
    img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, \
								&img.endian); // 画像データの取得

    draw_line(x0, y0, x1, y1, 0xFFFFFF, &img); // 線を描画

    mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0); // 画像をウィンドウに表示
    mlx_loop(mlx_ptr); // イベントループ開始

    return 0;
}