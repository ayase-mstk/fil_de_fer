#include "../fdf.h"

void	lst_print(t_map *map)
{
	int			i;
	int			j;
	t_mappoint	now;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			now = map->array[i][j];
			ft_printf("x=%d, y=%d, z=%d, color=%x\n", now.x, now.y, now.z, now.color);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
