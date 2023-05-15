#include <X11/keysym.h>
#include "mlx.h"
#include "fdf.h"
// #include "keymap.h"

#define HEIGHT 1080
#define WIDTH 1920

void	my_mlx_pixel_put(t_img *img, int x, int y, double z)
{
	char	*dst;
	int		color;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	if (z <= 0)
		color = 0xFFFFFF;
	else
		color = 0x00FFFF;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

int	deal_key(int keycode, t_data *data)
{
	// printf("keycode : %d\n", keycode);s
	// printf("XK_Escape : %d\n", KEY_ESCAPE);
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
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

void	draw_right(t_map *map, t_img *img, int i, int j)
{
	double	dx;
	double	dy;
	double	sx;
	double	sy;
	double	err;

	dx = fabs(map->array[i][j + 1].x - map->array[i][j].x);
	dy = fabs(map->array[i][j + 1].y - map->array[i][j].y);
	sx = map->array[i][j].x < map->array[i][j + 1].x ? 1 : -1;
	sy = map->array[i][j].y < map->array[i][j + 1].y ? 1 : -1;
	err = dx - dy;
	while ((fabs(map->array[i][j + 1].x - map->array[i][j].vx) > 1.1) && \
			(fabs(map->array[i][j + 1].y - map->array[i][j].vy) > 1.1))
	{
		my_mlx_pixel_put(img, map->array[i][j].vx, map->array[i][j].vy, map->array[i][j].z);
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
	while ((fabs(map->array[i + 1][j].x - map->array[i][j].vx) > 1.1 && \
			fabs(map->array[i + 1][j].y - map->array[i][j].vy) > 1.1))
	{
		my_mlx_pixel_put(img, map->array[i][j].vx, map->array[i][j].vy, 0x00FFFF);
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

	mlx_hook(data.win_ptr, 17, 1L<<17, close_window, &data);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	// mlx_mouse_hook(data.win_ptr, deal_mouse, &data);
	mlx_expose_hook(data.win_ptr, expose_hook, map);
	// mlx_mouse_move(data.win_ptr, 250, 250);
	mlx_loop(data.mlx_ptr);
	// クリックしたら終了する処理を実装する。
}

// cc -Wall -Wextra -Werror main.c -Imlx -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit