#include "fdf.h"

char	*check_color(char *strarr)
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

void	set_z(t_map *map, char *strarr, int row, int col)
{
	if (check_color(strarr) != NULL)
	{
		map->array[row][col].color = ft_atoi_base(check_color(strarr), \
						"0123456789ABCDEF", "0123456789abcdef");
		ft_printf("%x\n", map->array[row][col].color);
		map->array[row][col].z = 40 * (double)ft_atoi(&strarr[col]);
	}
	else
	{
		map->array[row][col].color = 0xFFFFFF;
		map->array[row][col].z = 40 * (double)ft_atoi(strarr);
	}
}

void	store_map(t_map *map, char **strarr, int row)
{
	int	size;
	int	col;

	size = 0;
	while (strarr[size])
		size++;
	map->array[row] = (t_mappoint *)malloc(sizeof(t_mappoint) * (size + 1));
	if (map->array[row] == NULL)
		maparray_and_strarr_free(map, strarr);
	col = 0;
	while (strarr[col])
	{
		map->array[row][col].x = 40.0 * (double)row;
		map->array[row][col].y = 40.0 * (double)col;
		set_z(map, strarr[col], row, col);
		col++;
	}
	if (map->col == 0)
		map->col = col;
	if (map->col != col)
		maparray_and_strarr_free(map, strarr);
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
	map->xy.x_max = 0;
	map->xy.x_min = 0;
	map->xy.y_max = 0;
	map->xy.y_min = 0;
	split_map(map, lines);
}
