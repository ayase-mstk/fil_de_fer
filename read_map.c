#include "fdf.h"

char	*color_is_designated(char *strarr)
{
	int	i;

	i = 0;
	while (strarr[i])
	{
		if (strarr[i] == ',')
			return (strarr + i + 1);
		i++;
	}
	return (NULL);
}

void	set_z(t_mappoint *point, char *strarr)
{
	if (color_is_designated(strarr))
	{
		point->color = ft_atoi_base(color_is_designated(strarr), \
						"0123456789ABCDEF", "0123456789abcdef");
		point->z = ft_atoi(strarr);
	}
	else
	{
		point->color = INDIGO;
		point->z = ft_atoi(strarr);
	}
}

void	store_map(t_map *map, char **strarr, int row)
{
	int	col;

	col = 0;
	while (strarr[col])
		col++;
	map->array[row] = (t_mappoint *)malloc(sizeof(t_mappoint) * (col + 1));
	if (map->array[row] == NULL)
		maparray_and_strarr_free(map, strarr);
	if (map->col == 0)
		map->col = col;
	if (map->col != col)
	{
		ft_putstr_fd("Invalid map(widths are not same)\n", 2);
		maparray_and_strarr_free(map, strarr);
	}
	col = 0;
	while (strarr[col])
	{
		map->array[row][col].x = row;
		map->array[row][col].y = col;
		set_z(&map->array[row][col], strarr[col]);
		map_range(map, row, col, map->array[row][col].z);
		col++;
	}
}

void	split_map(t_map *map, char *lines[])
{
	int			i;
	int			row;
	char		**strarr;

	i = 0;
	row = 0;
	while (lines[row])
		row++;
	map->array = (t_mappoint **)malloc(sizeof(t_mappoint *) * (row + 1));
	if (map->array == NULL)
		exit(1);
	map->array[row] = NULL;
	map->row = row;
	while (i < row)
	{
		strarr = ft_split(lines[i], ' ');
		free(lines[i]);
		store_map(map, strarr, i);
		free_strarr(strarr);
		i++;
	}
	set_scale(map);
	scale_points(map);
}

void	read_map(t_map *map, char *map_name)
{
	size_t		i;
	int			fd;
	char		*lines[1024];

	i = 0;
	fd = open(map_name, O_RDONLY);
	while (1)
	{
		lines[i] = get_next_line(fd);
		if (lines[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	map->col = 0;
	map->row = 0;
	map->range.x_max = 0;
	map->range.x_min = 0;
	map->range.y_max = 0;
	map->range.y_min = 0;
	map->range.z_max = 0;
	map->range.z_min = 0;
	map->range.color_max = 0x000000;
	map->range.color_min = 0xFFFFFF;
	split_map(map, lines);
}
