/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:29:39 by mahayase          #+#    #+#             */
/*   Updated: 2023/01/19 18:29:53 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*p;

	if (!n)
		return (NULL);
	i = 0;
	uc = (unsigned char)c;
	p = (unsigned char *)s;
	while (i < n)
	{
		if (p[i] == uc)
			return (&p[i]);
		i++;
	}
	return (NULL);
}
