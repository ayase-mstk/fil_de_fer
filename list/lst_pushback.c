#include "../fdf.h"

void	lst_pushback(t_map *map, int x, int y, int z)
{
	t_mappoint	*new;
	t_mappoint	*last;

	new = (t_mappoint *)malloc(sizeof(t_mappoint));
	last = lst_last(map);
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	last->next = new;
}
