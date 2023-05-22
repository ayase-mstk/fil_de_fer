#include "fdf.h"

void	set_axis(int keycode, t_map *map)
{
	if (keycode == XK_x)
		map->axis = X;
	else if (keycode == XK_y)
		map->axis = Y;
	else if (keycode == XK_z)
		map->axis = Z;
}

static	unsigned int	ft_check_num(char c, char *base1, char *base2)
{
	int	i;

	i = 0;
	while (base1[i])
	{
		if (c == base1[i] || c == base2[i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base1, char *base2)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result *= 16;
		result += 0x0 + ft_check_num(str[i], base1, base2);
		i++;
	}
	return (result);
}

void	lst_print(t_map *map, t_mappoint **array)
{
	int			i;
	int			j;
	t_mappoint	now;

	i = 0;
	while (i < map->row && array[i])
	{
		j = 0;
		while (j < map->col)
		{
			now = array[i][j];
			ft_printf("x=%d, y=%d, z=%d, color=%x\n", \
						now.x, now.y, now.z, now.color);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
