#include "../fdf.h"

t_map	*lst_init(void)
{
	t_map		*map;
	t_mappoint	*head;

	map = (t_map *)malloc(sizeof(t_map));
	head = (t_mappoint *)malloc(sizeof(t_mappoint));
	head->next = NULL;
	map->head = head;
	map->row = 0;
	map->col = 0;
	return (map);
}

// head -> head
//		<- head
//  ^
//  |
// map