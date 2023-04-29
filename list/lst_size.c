#include "../fdf.h"

size_t	lst_size(t_map *map)
{
	size_t		size;
	t_mappoint	*tmp;

	size = 0;
	tmp = map->head->next;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
