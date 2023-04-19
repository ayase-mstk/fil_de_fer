#include "fdf.h"

int	input_data(t_point *point)
{
	int		fd;
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	point = (t_point *)malloc(sizeof(t_point) * map_size());
	fd = open("input.fdf", O_RDONLY);
	while (1)
	{
		j = 0;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (line[j] == '\n' || line[j] == "\0")
		{
			point->x = i;
			point->y = j;
			point->z = line[j];
			
			j++;
		}
		free(line);
		i++;
	}
	return (0);
}

int main(void)
{
	t_point	*point;

	point = input_data(point);
	return (0);
}