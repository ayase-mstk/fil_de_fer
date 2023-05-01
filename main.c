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
	int	col;

	col = 0;
	while (strarr[col])
	{
		lst_pushback(map, row, col, ft_atof(strarr[col]));
		col++;
	}
	if (map->col == 0)
		map->col = col + 1;
}

void	read_map(t_map *map, char *map_name)
{
	size_t		i;
	int			fd;
	char		*line;
	char		**strarr;

	i = 0;
	fd = open(map_name, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		strarr = ft_split(line, ' ');
		store_map(map, strarr, i);
		free(line);
		line = NULL;
		free_strarr(strarr);
		i++;
	}
	map->row = i + 1;
	close(fd);
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2 && ac != 4)
		exit(0);
	map = lst_init();
	read_map(map, av[1]);
	// lst_print(map);
	ft_mlx(map);
	return (0);
}
