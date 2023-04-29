#include "../fdf.h"

void	lst_print(t_map *list)
{
	t_mappoint	*tmp;

	tmp = list->head->next;
	while (tmp != NULL)
	{
		ft_printf("x=%d, y=%d, z=%d\n", tmp->x, tmp->y, tmp->z);
		tmp = tmp->next;
	}
}
