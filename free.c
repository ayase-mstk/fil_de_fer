/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masa <masa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:01:35 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/22 19:01:09 by masa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_lines(char **lines, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		free(lines[i]);
		lines[i] = NULL;
		i--;
	}
	lines = NULL;
}

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

void	free_iso(t_map *map, int size)
{
	int	i;

	if (map->iso == NULL)
		return ;
	i = size - 1;
	while (i >= 0)
	{
		free(map->iso[i]);
		map->iso[i] = NULL;
		i--;
	}
	if (map->iso)
		free(map->iso);
	map->iso = NULL;
}

void	free_para(t_map *map, int size)
{
	int	i;

	if (map->para == NULL)
		return ;
	i = size - 1;
	while (i >= 0)
	{
		free(map->para[i]);
		map->para[i] = NULL;
		i--;
	}
	if (map->para)
		free(map->para);
	map->para = NULL;
}

void	free_map(t_map *map, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		free(map->array[i]);
		map->array[i] = NULL;
		i--;
	}
	if (map->array)
		free(map->array);
	map->array = NULL;
	free_iso(map, map->row);
	free_para(map, map->row);
	if (map->data)
		free(map->data);
	map->data = NULL;
	if (map->img)
		free(map->img);
	map->img = NULL;
	if (map)
		free(map);
	map = NULL;
}
