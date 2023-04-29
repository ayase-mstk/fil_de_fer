#include "../fdf.h"

t_mappoint	*lst_last(t_map *map)
{
	t_mappoint	*tmp;

	tmp = map->head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
