#include "fdf.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	set_variables(t_mappoint pre, t_mappoint next, t_bresenham *vars)
{
	vars->extent.x = ft_abs(next.x - pre.x);
	vars->extent.y = ft_abs(next.y - pre.y);
	vars->slope.x = ft_slope(pre.x, next.x);
	vars->slope.y = ft_slope(pre.y, next.y);
	vars->error = 0;
	if (vars->extent.x > vars->extent.y)
		vars->delta = (double)vars->extent.y / (double)vars->extent.x;
	else
		vars->delta = (double)vars->extent.x / (double)vars->extent.y;
}

static void	bresenham_util(int *now, int slope, double *error, double delta)
{
	*error += delta;
	if (*error >= 0.5)
	{
		*now += slope;
		*error -= 1.0;
	}
}

// int	color_bresenham(t_mappoint pre, t_mappoint now, t_mappoint next, t_point extent)
// {
// 	double	color_delta;
// 	double	color_slope;
// 	double	now_color;

// 	if (pre.color == next.color)
// 		return (pre.color);
// 	now_color = pre.color;
// 	color_slope = ft_slope(pre.color, next.color);
// 	if (extent.x > extent.y)
// 	{
// 		color_delta = (double)ft_abs(next.color - pre.color) \
// 					/ (double)extent.x;
// 		while (now.x++ != next.x)
// 			now_color += color_delta * color_slope;
// 	}
// 	else
// 	{
// 		color_delta = (double)ft_abs(next.color - pre.color) \
// 					/ (double)extent.y;
// 		while (now.y++ != next.y)
// 			now_color += color_delta * color_slope;
// 	}
// 	return ((int)now_color);
// }

static void	draw_bresenham(t_mappoint pre, t_mappoint next, t_map *map)
{
	t_mappoint	now;
	t_bresenham	vars;

	set_variables(pre, next, &vars);
	now = pre;
	if (vars.extent.x > vars.extent.y)
	{
		while (now.x != next.x)
		{
			my_mlx_pixel_put(map->img, now.x, now.y, \
							now_color(pre, now, next, map));
			now.x += vars.slope.x;
			bresenham_util(&now.y, vars.slope.y, &vars.error, vars.delta);
		}
	}
	else
	{
		while (now.y != next.y)
		{
			my_mlx_pixel_put(map->img, now.x, now.y, \
							now_color(pre, now, next, map));
			now.y += vars.slope.y;
			bresenham_util(&now.x, vars.slope.x, &vars.error, vars.delta);
		}
	}
}

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
			if (j != map->col - 1)
				draw_bresenham(array[i][j], array[i][j + 1], map);
			if (i != map->row - 1)
				draw_bresenham(array[i][j], array[i + 1][j], map);
			j++;
		}
		i++;
	}
}
