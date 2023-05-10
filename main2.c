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

void	store_map(t_map *map, char **strarr, int row)
{
	int	size;
	int	col;

	size = 0;
	while (strarr[size])
		size++;
	map->array[row] = (t_mappoint *)malloc(sizeof(t_mappoint) * (size + 1));
	if (map->array[row] == NULL)
		exit(1);
	col = 0;
	while (strarr[col])
	{
		map->array[row][col].x = 40.0 * row;
		map->array[row][col].y = 40.0 * col;
		map->array[row][col].z = 40 * ft_atof(strarr[col]);
		col++;
	}
	if (map->col == 0)
		map->col = col;
	if (map->col != col)
		exit(1);
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
		store_map(map, strarr, i);
		free_strarr(strarr);
		free(lines[i]);
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
	split_map(map, lines);
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2 && ac != 4)
		exit(0);
	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		exit(1);
	read_map(map, av[1]);
	ft_isometric_projection(map);
	// ft_rotation_z(map, 5.0);
	// ft_rotation_x(map, 36.0);
	// ft_rotation_y(map, -15.0);
	lst_print(map);
	ft_mlx(map);
	return (0);
}
