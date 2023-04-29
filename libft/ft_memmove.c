/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:30:37 by mahayase          #+#    #+#             */
/*   Updated: 2023/01/19 18:30:47 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*p;
	const char	*q;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		p = (char *)dest;
		q = (const char *)src;
		while (n--)
			*p++ = *q++;
	}
	else
	{
		p = (char *)dest + (n - 1);
		q = (const char *)src + (n - 1);
		while (n--)
			*p-- = *q--;
	}
	return (dest);
}
