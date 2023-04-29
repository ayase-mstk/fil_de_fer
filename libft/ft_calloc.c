/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:06:49 by mahayase          #+#    #+#             */
/*   Updated: 2023/01/11 21:07:13 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			alsize;
	void			*calloc;

	if (!size || !count)
	{
		count = 1;
		size = 1;
	}
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	alsize = size * count;
	calloc = (void *)malloc(alsize);
	if (calloc == NULL)
		return (NULL);
	ft_bzero(calloc, alsize);
	return (calloc);
}
