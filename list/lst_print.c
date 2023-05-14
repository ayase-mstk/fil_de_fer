#include "../fdf.h"

void	lst_print(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			printf("x=%lf, y=%lf, z=%lf\n", map->array[i][j].x, map->array[i][j].y, map->array[i][j].z); //delete printf
			j++;
		}
		printf("\n"); //delete printf
		i++;
	}
}
