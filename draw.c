#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_slope(double a, double b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

void	draw_right(t_mappoint **array, t_img *img, int i, int j)
{
	t_point		delta;
	t_point		slope;
	t_mappoint	now;
	t_mappoint	next;
	int			err;

	delta.x = ft_abs(array[i][j + 1].x - array[i][j].x);
	delta.y = ft_abs(array[i][j + 1].y - array[i][j].y);
	slope.x = ft_slope(array[i][j].x, array[i][j + 1].x);
	slope.y = ft_slope(array[i][j].y, array[i][j + 1].y);
	err = delta.x - delta.y;
	now = array[i][j];
	next = array[i][j + 1];
	while (now.vx != next.x && now.vy != next.y)
	{
		my_mlx_pixel_put(img, now.vx, now.vy, now_color(array[i][j], now, next, delta));
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

void	draw_down(t_mappoint **array, t_img *img, int i, int j)
{
	t_point		delta;
	t_point		slope;
	t_mappoint	now;
	t_mappoint	next;
	int			err;

	delta.x = ft_abs(array[i + 1][j].x - array[i][j].x);
	delta.y = ft_abs(array[i + 1][j].y - array[i][j].y);
	slope.x = ft_slope(array[i][j].x, array[i + 1][j].x);
	slope.y = ft_slope(array[i][j].y, array[i + 1][j].y);
	err = delta.x - delta.y;
	now = array[i][j];
	next = array[i + 1][j];
	while (now.vx != next.x && now.vy != next.y)
	{
		my_mlx_pixel_put(img, now.vx, now.vy, now_color(array[i][j], now, next, delta));
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
				draw_right(map->array, img, i, j);
			map->array[i][j].vx = map->array[i][j].x;
			map->array[i][j].vy = map->array[i][j].y;
			if (i != map->row - 1)
				draw_down(map->array, img, i, j);
			j++;
		}
		i++;
	}
}
