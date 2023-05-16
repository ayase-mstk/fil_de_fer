#include "fdf.h"

void	free_strarr(char **strarr)
{
	int	i;

	i = 0;
	while (strarr[i])
	{
		free(strarr[i]);
		strarr[i] = NULL;
		i++;
	}
	free(strarr);
	strarr = NULL;
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->array[i])
	{
		free(map->array[i]);
		map->array[i] = NULL;
		i++;
	}
	free(map->array);
	map->array = NULL;
	free(map);
	map = NULL;
}

void	maparray_and_strarr_free(t_map *map, char **strarr)
{
	free_map(map);
	free_strarr(strarr);
	exit(1);
}
