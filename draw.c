#include "fdf.h"

int ok = 0;

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	ft_slope(double a, double b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

static void	draw_line(t_mappoint pre, t_mappoint next, t_img *img)
{
	t_mappoint	now;
	t_point		delta;
	t_point		slope;
	int			err;

	delta.x = ft_abs(next.x - pre.x);
	delta.y = ft_abs(next.y - pre.y);
	slope.x = ft_slope(pre.x, next.x);
	slope.y = ft_slope(pre.y, next.y);
	err = delta.x - delta.y;
	now = pre;
	while (now.x != next.x && now.y != next.y)
	{
		my_mlx_pixel_put(img, now.x, now.y, now_color(pre, now, next, delta));
		if (err * 2 > -delta.y)
		{
			err -= delta.y;
			now.x += slope.x;
		}
		if (err * 2 < delta.x)
		{
			err += delta.x;
			now.y += slope.y;
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

void	draw_image(t_map *map, t_mappoint **array)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			// printf("%d\n", ok++);
			if (j != map->col - 1)
				draw_line(array[i][j], array[i][j + 1], map->img);
			if (i != map->row - 1)
				draw_line(array[i][j], array[i + 1][j], map->img);
			j++;
		}
		i++;
	}
}
