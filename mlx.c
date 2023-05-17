#include <X11/keysym.h>
#include "mlx.h"
#include "fdf.h"
// #include "keymap.h"

#define HEIGHT 1080
#define WIDTH 1920
#define SLOPE(a,b) (a < b ? 1 : -1)

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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

double	now_position(double pre, double now, double next, double delta)
{
	return ((now - pre) / delta);
}

unsigned int	get_color(unsigned int now, unsigned int next, double now_pos)
{
	return ((unsigned int)((1 - now_pos) * now + now_pos * next));
}

unsigned int	now_color(t_mappoint *now, t_mappoint *next, t_point delta)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	double			now_pos;

	if (now->color == next->color)
		return (now->color);
	if (delta.x > delta.y)
		now_pos = now_position(now.x, next.x, delta.x);
	else
		now_pos = now_position(now.y, next.y, delta.y);
	red = get_color(now->color >> 16, next->color >> 16, now_pos);
	green = get_color(now->color >> 8, next->color >> 8, now_pos);
	blue = get_color(now->color, next->color, now_pos);
	return (red << 16 | green << 8 | blue);
}

int	ft_slope(double a, double b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

void	draw_right(t_map *map, t_img *img, int i, int j)
{
	t_point		delta;
	t_point		slope;
	t_mappoint	now;
	t_mappoint	next;
	double		err;

	delta.x = fabs(map->array[i][j + 1].x - map->array[i][j].x);
	delta.y = fabs(map->array[i][j + 1].y - map->array[i][j].y);
	slope.x = slope(map->array[i][j].x, map->array[i][j + 1].x);
	slope.y = slope(map->array[i][j].y, map->array[i][j + 1].y);
	err = delta.x - delta.y;
	now = map->array[i][j];
	next = map->array[i][j + 1];
	while ((fabs(next.x - now.vx) > 1) && (fabs(next.y - now.vy) > 1))
	{
		my_mlx_pixel_put(img, now.vx, now.vy, now_color(now, next, delta));
		if (err * 2 > -delta.y)
		{
			err -= delta.y;
			now.vx += slope.x;
		}
		if (err * 2 < delta.x)
		{
			err += delta.x;
			now.vy += slope.y;
		}
	}
}
//errは、x軸方向の誤差を表しています。
//err * 2 > -delta.yは、x軸方向の誤差が-y軸方向の距離より大きい場合を表しています。
//err * 2 < delta.xは、x軸方向の誤差がx軸方向の距離より小さい場合を表しています。
//err -= delta.yは、x軸方向の誤差から-y軸方向の距離を引いた値をx軸方向の誤差に代入することを表しています。
//now.vx += slope.xは、現在の座標のx軸方向に傾きを足した値を現在の座標のx軸方向に代入することを表しています。
//err += delta.xは、x軸方向の誤差にx軸方向の距離を足した値をx軸方向の誤差に代入することを表しています。
//now.vy += slope.yは、現在の座標のy軸方向に傾きを足した値を現在の座標のy軸方向に代入することを表しています。

void	draw_down(t_map *map, t_img *img, int i, int j)
{
	double	dx;
	double	dy;
	double	sx;
	double	sy;
	double	err;

	dx = fabs(map->array[i + 1][j].x - map->array[i][j].x);
	dy = fabs(map->array[i + 1][j].y - map->array[i][j].y);
	sx = map->array[i][j].x < map->array[i + 1][j].x ? 1 : -1;
	sy = map->array[i][j].y < map->array[i + 1][j].y ? 1 : -1;
	err = dx - dy;
	while ((fabs(map->array[i + 1][j].x - map->array[i][j].vx) > 1 && \
			fabs(map->array[i + 1][j].y - map->array[i][j].vy) > 1))
	{
		my_mlx_pixel_put(img, map->array[i][j].vx, map->array[i][j].vy, map->array[i][j].color);
		if (err * 2 > -dy)
		{
			err -= dy;
			map->array[i][j].vx += sx;
		}
		if (err * 2 < dx)
		{
			err += dx;
			map->array[i][j].vy += sy;
		}
	}
}

void	draw_line(t_map *map, t_img *img)
{
	int	i;
	int	j;

	pos_set(map, WIDTH, HEIGHT);
	repos_xy(map);
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			map->array[i][j].vx = map->array[i][j].x;
			map->array[i][j].vy = map->array[i][j].y;
			if (j != map->col - 1)
				draw_right(map, img, i, j);
			map->array[i][j].vx = map->array[i][j].x;
			map->array[i][j].vy = map->array[i][j].y;
			if (i != map->row - 1)
				draw_down(map, img, i, j);
			j++;
		}
		i++;
	}
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