#include "../fdf.h"

void	lst_free(t_map *map)
{
	t_mappoint	*tmp;
	t_mappoint	*next;

	tmp = map->head;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(map);
}
