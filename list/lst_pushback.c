#include "../fdf.h"

void	lst_pushback(t_map *map, double x, double y, double z)
{
	t_mappoint	*new;
	t_mappoint	*last;

	new = (t_mappoint *)malloc(sizeof(t_mappoint));
	last = lst_last(map);
	last->next = new;
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
}
