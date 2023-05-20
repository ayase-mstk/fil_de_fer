#include "fdf.h"

static double	now_position(int pre, int now, int delta)
{
	return ((double)(now - pre) / (double)delta);
}

static int	get_color(int pre, int next, double now_pos)
{
	return ((int)((1 - now_pos) * pre + now_pos * next));
}

int	now_color(t_mappoint pre, t_mappoint now, t_mappoint next, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	now_pos;

	if (pre.color == next.color)
		return (pre.color);
	if (delta.x > delta.y)
		now_pos = now_position(pre.x, now.x, delta.x);
	else
		now_pos = now_position(pre.y, now.y, delta.y);
	red = get_color((pre.color >> 16) & 0xFF, (next.color >> 16) & 0xFF, now_pos);
	green = get_color((pre.color >> 8) & 0xFF, (next.color >> 8) & 0xFF, now_pos);
	blue = get_color(pre.color & 0xFF, next.color & 0xFF, now_pos);
	return ((red << 16) | (green << 8) | blue);
}
