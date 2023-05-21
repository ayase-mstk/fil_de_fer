#include "fdf.h"

void	free_strarr(char **strarr, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		free(strarr[i]);
		strarr[i] = NULL;
		i--;
	}
	free(strarr);
	strarr = NULL;
}

static	void	free_iso(t_map *map, int size)
{
	int	i;

	if (map->iso == NULL)
		return ;
	i = size - 1;
	while (i >= 0)
	{
		free(map->iso[i]);
		map->iso[i] = NULL;
		i--;
	}
	if (map->iso)
		free(map->iso);
	map->iso = NULL;
}

static	void	free_para(t_map *map, int size)
{
	int	i;

	if (map->para == NULL)
		return ;
	i = size - 1;
	while (i >= 0)
	{
		free(map->para[i]);
		map->para[i] = NULL;
		i--;
	}
	if (map->para)
		free(map->para);
	map->para = NULL;
}

void	free_map(t_map *map, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		free(map->array[i]);
		map->array[i] = NULL;
		i--;
	}
	if (map->array)
		free(map->array);
	map->array = NULL;
	free_iso(map, map->row);
	free_para(map, map->row);
	if (map)
		free(map);
	map = NULL;
}

void	maparray_and_strarr_free(t_map *map, char **strarr, int size)
{
	free_map(map, size);
	free_strarr(strarr, size);
	exit(1);
}
