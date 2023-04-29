/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:22:51 by mahayase          #+#    #+#             */
/*   Updated: 2023/01/10 16:23:16 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d_size;
	size_t	s_size;
	size_t	max_size;

	s_size = ft_strlen(src);
	if (dest == NULL && size == 0)
		return (s_size);
	d_size = ft_strlen(dest);
	if (size <= d_size)
		return (size + s_size);
	max_size = size - d_size - 1;
	i = 0;
	while (i < max_size)
	{
		if (src[i] == '\0')
			break ;
		dest[d_size + i] = src[i];
		i++;
	}
	dest[d_size + i] = '\0';
	return (d_size + s_size);
}
